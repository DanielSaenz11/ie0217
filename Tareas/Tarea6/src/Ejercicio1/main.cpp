/**
 * @file main.cpp
 * @brief Programa principal para simular el sistema de soporte técnico paralelo.
 * @details Este archivo contiene el programa principal que inicializa y ejecuta los hilos de clientes y operadores
 *          para simular el sistema de soporte técnico paralelo. Los hilos de clientes generan solicitudes que se colocan 
 *          en un buffer compartido, mientras que los operadores procesan dichas solicitudes de forma concurrente. 
 *          La función `monitorear_rendimiento` se ejecuta al final para mostrar estadísticas de rendimiento.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 10/11/2024
 */

#include "solicitudes.hpp"
#include <iostream>
#include <thread>
#include <vector>


int main() {
    // Declaración de vector de threads para clientes y operadores
    std::vector<std::thread> clientes, operadores;

    // Crear hilos de clientes
    for (int i = 0; i < NUM_CLIENTES; ++i) {
        clientes.emplace_back(cliente, i, SOLICITUDES_POR_CLIENTE);
    }

    // Crear hilos de operadores
    for (int i = 0; i < NUM_OPERADORES; ++i) {
        operadores.emplace_back(operador, i);
    }

    // Esperar a que terminen todos los clientes
    for (auto& hilo_cliente : clientes) {
        hilo_cliente.join();
    }

    // Indicar que todos los clientes terminaron de generar solicitudes
    produccion_finalizada = true;
    
    // Notifica a todos los hilos de operadores en espera
    cv_operador.notify_all();

    // Esperar a que terminen todos los operadores
    for (auto& hilo_operador : operadores) {
        hilo_operador.join();
    }

    // monitorear_rendimiento(NUM_CLIENTES, NUM_OPERADORES);
    std::cout << "Todos los clientes y operadores han terminado." << std::endl;

    return 0;
}