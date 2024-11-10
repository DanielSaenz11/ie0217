/**
 * @file main.cpp
 * @brief Programa principal para ejecutar DataProcessor con entrada validada.
 * 
 * Este archivo contiene la función principal y la función de validación de entrada del tamaño del arreglo.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 10/11/2024
 */

#include "DataProcessor.hpp"
#include <iostream>
#include <limits>

/**
 * @brief Función para validar la entrada del usuario como un número entero adecuado para la entrada.
 * 
 * Solicita al usuario que ingrese un número entero positivo y valida que la entrada sea correcta.
 * 
 * @return `int` El valor ingresado por el usuario para size.
 */
int validarEntero() {

    // Variable para almacenar la entrada del usuario
    int valor;

    // Loop para validar la entrada del usuario hasta recibir una adecuada
    while (true) {
        // Ingreso del valor
        std::cout << "Enter size of data: ";
        std::cin >> valor;

        // Si la entrada fue incorrecta
        if (std::cin.fail() || valor <= 0) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar la entrada no válida
            std::cout << "Error: Invalid size.\n";
        }
        else {
            // En caso exitoso, se retorna el valor ingresado por el usuario
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
    }
}

/**
 * @brief Función principal para la ejecución del programa.
 * 
 * Crea un objeto DataProcessor, realiza las operaciones de población, procesamiento e impresión
 * de datos, y calcula el promedio.
 * 
 * @return `int` Estado del programa. 0 al finalizar la ejecución exitosamente.
 */
int main() {
    // Ingreso de la variable size
    int size = validarEntero();

    // Asignar memoria para instancia de DataProcessor
    DataProcessor* processor = new DataProcessor(size);

    // Agregar elementos al array (poblar)
    processor->populateData();

    // Llamar al proceso concurrente definido
    processor->concurrentProcess();

    // Imprimir cada elemento del array
    // processor->printData();

    // Imprimir resultado del promedio
    std::cout << "Average: " << processor->calculateAverage() << std::endl;

    // Liberar memoria reservada para el objeto DataProcessor
    delete processor;

    return 0;
}