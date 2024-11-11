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

/**
 * @brief Función principal para el sistema de soporte técnico paralelo.
 * @details La función principal configura e inicia los hilos de clientes y operadores, los cuales simulan
 *          el proceso de generación y atención de solicitudes en un sistema concurrente. Los hilos de clientes
 *          generan solicitudes que se almacenan en un buffer compartido, mientras que los operadores procesan
 *          dichas solicitudes. Una vez que todos los clientes han terminado de generar solicitudes, se marca el
 *          final de la producción y se notifica a todos los operadores para que finalicen su ejecución.
 * 
 * @return `int` Código de estado de la aplicación, retorna 0 si la ejecución fue exitosa.
 */
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

    std::cout << "Todos los clientes y operadores han terminado." << std::endl;

    return 0;
}