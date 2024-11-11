/**
 * @file soporte_tecnico.cpp
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
constexpr int TAMANO_BUFFER = 10; // Tamaño del buffer
std::queue<int> buffer; // Buffer modelado como una cola
std::mutex mtx; // Mutex para proteger el acceso al buffer
std::counting_semaphore<TAMANO_BUFFER> empty_slots(TAMANO_BUFFER); // Semáforo empty_slots: Tamaño inicial del buffer
std::counting_semaphore<TAMANO_BUFFER> full_slots(0); // Semáforo full_slots: Tamaño inicial de 0

// Variables de monitoreo
std::atomic<int> total_solicitudes_procesadas{0}; // Total de solicitudes procesadas
std::atomic<int> tiempo_espera_total_clientes{0}; // Tiempo de espera total de clientes
std::atomic<int> tiempo_espera_total_operadores{0}; // Tiempo de espera total de operadores

// Variables compartidas
std::condition_variable cv_cliente, cv_operador;
std::atomic<bool> produccion_finalizada{false};

// Generador de tiempos aleatorios para simular tiempos de espera
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(50, 150);


// Definición de función para los hilos de los clientes (productores)
void cliente(int id, int num_solicitudes) {
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
        tiempo_espera_total_clientes += std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

        // Bloque de código que bloquea el lock: Crea un scope
        {
            std::lock_guard<std::mutex> lock(mtx); // Bloquear porción de memoria compartida
            buffer.push(solicitud); // Realizar la solicitud
            std::cout << "Cliente " << id << " generó la solicitud " << solicitud << std::endl;
            // Desbloquear lock al salir del scope
        }

        // Incrementa el valor del contador de full_slots: Hay una nueva solicitud
        full_slots.release();

        // Notificar a un operador en espera de una solicitud en el buffer
        cv_operador.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen))); // Espera aleatoria entre solicitudes
    }
}

// Definición de función para los hilos de los operadores (consumidores)
void operador(int id) {
    // Bucle infinito que consume tareas
    while (true) {
        // Decrementa el valor del contador full_slots: Se consumió una solicitud
        full_slots.acquire();

        // Bloqueo exclusivo sobre mtx para que únicamente un hilo pueda acceder
        std::unique_lock<std::mutex> lock(mtx);

        // Hilo del operador en espera mientras no se cumple la condición en la función lambda
        // Permite que otros hilos accedan al buffer durante la espera
        cv_operador.wait(lock, [] { return !buffer.empty() || produccion_finalizada; });

        if (buffer.empty() && produccion_finalizada) {
            lock.unlock();
            empty_slots.release();  // Liberar el espacio ocupado en caso de estar dentro del buffer
            break; // Terminar si no hay más solicitudes
        }

        // Si el buffer no está vacío
        if (!buffer.empty()) {
            int solicitud = buffer.front(); // Obtener el elemento del frente de la cola
            buffer.pop(); // Elimina el elemento sacado previamente
            total_solicitudes_procesadas++; // Aumenta el número de solicitudes procesadas
            std::cout << "Operador " << id << " procesó la solicitud " << solicitud << std::endl;

            empty_slots.release(); // Incrementa el contador de espacios libres en el buffer
        }
        
        // Notificar a un cliente en espera de un espacio en el buffer
        cv_cliente.notify_one();

        lock.unlock(); // Desbloquea el lock

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Tiempo de procesamiento simulado
    }
}

// Monitoreo de rendimiento y métricas
void monitorear_rendimiento(int num_clientes, int num_operadores) {
    // Cálculo de tiempo de espera promedio entre clientes
    int espera_promedio_clientes = tiempo_espera_total_clientes / (num_clientes * TAMANO_BUFFER);

    // Cálculo de tiempo de espera promedio entre operadores
    int espera_promedio_operadores = tiempo_espera_total_operadores / (num_operadores * TAMANO_BUFFER);
    
    // Imprimir resultados
    std::cout << "\n--- Métricas de Rendimiento ---" << std::endl;
    std::cout << "Total de solicitudes procesadas: " << total_solicitudes_procesadas << std::endl;
    std::cout << "Tiempo de espera promedio para clientes: " << espera_promedio_clientes << " ms" << std::endl;
    std::cout << "Tiempo de espera promedio para operadores: " << espera_promedio_operadores << " ms" << std::endl;
    std::cout << "Tamaño del buffer: " << TAMANO_BUFFER << std::endl;
}
