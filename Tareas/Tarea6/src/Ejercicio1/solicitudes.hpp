/**
 * @file solicitudes.hpp
 * @brief Definición de funciones y variables para el sistema de soporte técnico paralelo.
 * @details Este archivo contiene las declaraciones de las funciones principales del sistema
 *          de soporte técnico paralelo, que simula un servicio en el cual múltiples hilos de clientes generan
 *          solicitudes y múltiples hilos de operadores las procesan de forma concurrente. 
 *          Las funciones y variables de sincronización se declaran aquí para que puedan ser utilizadas en 
 *          el archivo de implementación. Las funciones de cliente y operador manejan la producción y consumo 
 *          de solicitudes en un buffer compartido, controlando el acceso mediante semáforos, mutex y 
 *          variables de condición.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 10/11/2024
 */

#ifndef SOPORTE_TECNICO_HPP
#define SOPORTE_TECNICO_HPP

#define NUM_CLIENTES 4
#define NUM_OPERADORES 3
#define SOLICITUDES_POR_CLIENTE 10

#include <condition_variable>
#include <atomic>

extern std::condition_variable cv_cliente, cv_operador; // Variables de condición para cliente y operador
extern std::atomic<bool> produccion_finalizada; // Booleano para indicar si la producción finalizó

/**
 * @brief Función para generar solicitudes por parte de los clientes.
 * @details Cada cliente genera solicitudes y las deposita en el buffer compartido de manera concurrente. 
 * La función controla la sincronización usando semáforos y mutex para garantizar un acceso seguro al buffer,
 * además de simular tiempos de espera entre solicitudes.
 * 
 * @param id Identificador del cliente.
 * @param num_solicitudes Número de solicitudes a generar por cada cliente.
 * @return `void`
 */
void cliente(int id, int num_solicitudes);

/**
 * @brief Función para procesar solicitudes por parte de los operadores.
 * @details Cada operador consume solicitudes del buffer compartido, simulando el procesamiento de cada 
 * solicitud mediante pausas. La función controla el acceso concurrente al buffer utilizando semáforos 
 * y mutex, permitiendo que un sólo operador acceda al buffer en cada momento.
 * 
 * @param id Identificador del operador.
 * @return `void`
 */
void operador(int id);

/**
 * @brief Función para monitorear y mostrar las métricas de rendimiento.
 * @details La función calcula y muestra el tiempo promedio de espera de los clientes y el tiempo de 
 * procesamiento promedio de los operadores. Se usa para evaluar el rendimiento del sistema de soporte 
 * técnico paralelo en diferentes configuraciones de clientes y operadores.
 * 
 * @param num_clientes Número de clientes que generaron solicitudes.
 * @param num_operadores Número de operadores que procesaron solicitudes.
 * @return void
 */
void monitorear_rendimiento(int num_clientes, int num_operadores);

#endif // SOPORTE_TECNICO_HPP
