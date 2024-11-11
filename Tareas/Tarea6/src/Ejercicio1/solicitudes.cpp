/**
 * @file solicitudes.cpp
 * @brief Implementación de las funciones para el sistema de soporte técnico paralelo.
 * @details Este archivo contiene la implementación de las funciones definidas en el archivo de cabecera.
 *          Aquí se desarrollan las operaciones de los hilos de clientes y operadores, que utilizan mecanismos
 *          de sincronización para proteger el acceso al buffer compartido. Las funciones implementan los 
 *          semáforos y mutex necesarios para evitar condiciones de carrera y asegurar un funcionamiento 
 *          eficiente del sistema. También incluye la función de monitoreo de rendimiento para registrar 
 *          el tiempo promedio de espera de los clientes y de procesamiento de los operadores.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 10/11/2024
 */

#include "solicitudes.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <semaphore>
#include <chrono>
#include <atomic>
#include <random>

// Configuración inicial
std::queue<int> buffer; // Buffer modelado como una cola
std::mutex mtx; // Mutex para proteger el acceso al buffer
std::counting_semaphore<TAMANO_BUFFER> empty_slots(TAMANO_BUFFER); // Semáforo empty_slots: Tamaño inicial del buffer
std::counting_semaphore<TAMANO_BUFFER> full_slots(0); // Semáforo full_slots: Tamaño inicial de 0

// Variables de monitoreo para operadores
std::atomic<int> tiempo_total_procesamiento_operadores{0};
std::atomic<int> tiempo_total_espera_operadores{0};
std::atomic<int> num_procesos_operadores{0};

// Variables de monitoreo para clientes
std::atomic<int> tiempo_total_procesamiento_clientes{0};
std::atomic<int> tiempo_total_espera_clientes{0};
std::atomic<int> num_procesos_clientes{0};

std::atomic<int> total_solicitudes_procesadas;

// Condition variables
std::condition_variable cv_cliente, cv_operador;

// Estado de producción
std::atomic<bool> produccion_finalizada{false};

// Definición de función para los hilos de los clientes (productores)
void cliente(int id, int num_solicitudes) {

    // Generador de tiempos aleatorios para simular tiempos de espera para cada hilo
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(50, 150);

    // Generar solicitudes por cliente
    for (int i = 0; i < num_solicitudes; ++i) {
        int solicitud = id * 100 + i; // Generación de la solicitud a partir del ID del cliente

        // Inicio de cronómetro para medir tiempo de espera
        auto inicio = std::chrono::high_resolution_clock::now();
        
        // Espacio disponible en buffer: Decrementa el valor del contador del semáforo empty_slots
        empty_slots.acquire();

        // Fin de cronómetro para medir tiempo de espera
        auto fin = std::chrono::high_resolution_clock::now();

        // Cálculo del tiempo de espera para el cliente
        tiempo_total_espera_clientes += std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        // Iniciar la medición del tiempo de procesamiento
        auto inicio_procesamiento = std::chrono::high_resolution_clock::now();

        // Bloque de código que bloquea el lock: Crea un scope
        {
            std::lock_guard<std::mutex> lock(mtx); // Bloquear porción de memoria compartida
            buffer.push(solicitud); // Realizar la solicitud
            std::cout << "Cliente " << id << " generó la solicitud " << solicitud << std::endl;
            // Desbloquear lock al salir del scope
        }

        // Fin del procesamiento y cálculo del tiempo de procesamiento
        auto fin_procesamiento = std::chrono::high_resolution_clock::now();
        int tiempo_procesamiento = std::chrono::duration_cast<std::chrono::microseconds>(fin_procesamiento - inicio_procesamiento).count();
        tiempo_total_procesamiento_clientes += tiempo_procesamiento;
        num_procesos_clientes++;

        // Incrementa el valor del contador de full_slots: Hay una nueva solicitud
        full_slots.release();

        // Notificar a un operador en espera de una solicitud en el buffer
        cv_operador.notify_one();

        std::this_thread::sleep_for(std::chrono::microseconds(dist(gen))); // Espera aleatoria entre solicitudes
    }
}

// Definición de función para los hilos de los operadores (consumidores)
void operador(int id) {
    // Bucle infinito que consume tareas
    while (true) {
        // Decrementa el valor del contador full_slots: Se consumió una solicitud si la producción no ha terminado
        if (!produccion_finalizada) {
            auto inicio = std::chrono::high_resolution_clock::now();
            full_slots.acquire();
            auto fin = std::chrono::high_resolution_clock::now();
            int tiempo_espera = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
            tiempo_total_espera_operadores += tiempo_espera;
        }

        {
            std::lock_guard<std::mutex> lock(mtx); // Proteger este scope el acceso a buffer

            if (produccion_finalizada && buffer.empty()) {
                break; // Salir
            }

            // Iniciar la medición del tiempo de procesamiento
            auto inicio_procesamiento = std::chrono::high_resolution_clock::now();

            // Si el buffer no está vacío
            if (!buffer.empty()) {
                int solicitud = buffer.front(); // Obtener el elemento del frente de la cola
                buffer.pop(); // Elimina el elemento sacado previamente
                total_solicitudes_procesadas++;
                std::cout << "Operador " << id << " procesó la solicitud " << solicitud << std::endl;
            }
            
            // Fin del procesamiento y cálculo del tiempo de procesamiento
            auto fin_procesamiento = std::chrono::high_resolution_clock::now();

            int tiempo_procesamiento = std::chrono::duration_cast<std::chrono::microseconds>(fin_procesamiento - inicio_procesamiento).count();
            tiempo_total_procesamiento_operadores += tiempo_procesamiento;
            num_procesos_operadores++;
        }


        empty_slots.release(); // Incrementa el contador de espacios libres en el buffer

        // Notificar a un cliente en espera de un espacio en el buffer
        cv_cliente.notify_one();

        std::this_thread::sleep_for(std::chrono::microseconds(100)); // Tiempo de procesamiento simulado
    }
}

// Monitoreo de rendimiento y métricas
void monitorear_rendimiento(int num_clientes, int num_operadores) {
    int espera_promedio_clientes = (num_procesos_clientes > 0) 
                                   ? tiempo_total_espera_clientes / num_procesos_clientes 
                                   : 0;
    int procesamiento_promedio_clientes = (num_procesos_clientes > 0) 
                                          ? tiempo_total_procesamiento_clientes / num_procesos_clientes 
                                          : 0;

    int espera_promedio_operadores = (num_procesos_operadores > 0) 
                                     ? tiempo_total_espera_operadores / num_procesos_operadores 
                                     : 0;
    int procesamiento_promedio_operadores = (num_procesos_operadores > 0) 
                                            ? tiempo_total_procesamiento_operadores / num_procesos_operadores 
                                            : 0;

    std::cout << "\n--- Métricas de Rendimiento ---" << std::endl;
    std::cout << "Total de solicitudes procesadas: " << total_solicitudes_procesadas << std::endl;
    std::cout << "Tiempo promedio de espera para clientes: " << espera_promedio_clientes << " us" << std::endl;
    std::cout << "Tiempo promedio de procesamiento para clientes: " << procesamiento_promedio_clientes << " us" << std::endl;
    std::cout << "Tiempo promedio de espera para operadores: " << espera_promedio_operadores << " us" << std::endl;
    std::cout << "Tiempo promedio de procesamiento para operadores: " << procesamiento_promedio_operadores << " us" << std::endl;
}

