/**
 * @file DataProcessor.hpp
 * @brief Declaración de la clase DataProcessor para procesar datos de manera concurrente.
 * 
 * Este archivo contiene la declaración de la clase DataProcessor, que permite realizar
 * operaciones sobre un arreglo de enteros, incluyendo el cálculo de la suma y el promedio,
 * con opciones para procesar los datos de forma concurrente.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 10/11/2024
 */

#ifndef DATAPROCESSOR_HPP
#define DATAPROCESSOR_HPP

#include <mutex>

/**
 * @class DataProcessor
 * @brief Clase para procesar datos almacenados en un arreglo de enteros.
 * 
 * La clase DataProcessor permite crear un arreglo de enteros, inicializar sus valores,
 * calcular su suma y promedio, y procesar sus datos con hilos.
 */
class DataProcessor {
public:
    /**
     * @brief Constructor que inicializa el arreglo de datos.
     * 
     * Crea un arreglo de enteros con el tamaño especificado y verifica que sea mayor que 0.
     * 
     * @param size Tamaño del arreglo de datos.
     */
    DataProcessor(int size);

    /**
     * @brief Destructor que libera la memoria asignada.
     * 
     * Libera la memoria reservada para el arreglo data.
     * 
     * @return `void`
     */
    ~DataProcessor();

    /**
     * @brief Inicializa el arreglo data con valores correspondientes a los índices multiplicados por 10.
     * 
     * Rellena el arreglo de datos con múltiplos de 10 (0, 10, 20, ...).
     * 
     * @return `void`
     */
    void populateData();

    /**
     * @brief Calcula la suma de los elementos en el arreglo data.
     * 
     * Recorre el arreglo y acumula los valores en una variable.
     * 
     * @return `int` La suma de los elementos en el arreglo data.
     */
    int calculateSum();

    /**
     * @brief Calcula el promedio de los elementos en el arreglo data.
     * 
     * Calcula el promedio de los valores en data llamando a calculateSum y dividiendo por size.
     * 
     * @return `double` El promedio de los elementos en el arreglo data.
     */
    double calculateAverage();

    /**
     * @brief Procesa los datos usando dos hilos.
     * 
     * Crea dos hilos para ejecutar processData de manera concurrente y espera a que terminen.
     * 
     * @return `void`
     */
    void concurrentProcess();

    /**
     * @brief Imprime el contenido del arreglo data.
     * 
     * Muestra en la consola cada índice del arreglo data.
     * 
     * @return `void`
     */
    void printData();

private:
    /// @brief Puntero del arreglo de datos
    int* data;

    /// @brief Tamaño del arreglo de datos
    int size;

    /// @brief Número de elementos inicializados en el arreglo;
    int initializedElements = 0;

    /// @brief Mutex para la sincronización entre hilos
    std::mutex mtx;

    /**
     * @brief Duplica cada elemento del arreglo data.
     * 
     * Multiplica cada elemento de data por 2 de forma protegida con `std::lock_guard`.
     * 
     * @return `void`
     */
    void processData();

};

#endif // DATAPROCESSOR_HPP