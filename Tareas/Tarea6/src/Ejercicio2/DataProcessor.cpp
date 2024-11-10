/**
 * @file DataProcessor.cpp
 * @brief Implementación de los métodos de la clase DataProcessor.
 * 
 * Este archivo contiene la implementación de la clase DataProcessor. Las funciones incluyen el cálculo de la suma y el promedio,
 * así como opciones para procesar los datos de forma concurrente.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 10/11/2024
 */

#include "DataProcessor.hpp"
#include <iostream>
#include <vector>
#include <thread>

// Definición del constructor
DataProcessor::DataProcessor(int size) : size(size), data(nullptr) {
    // Si el tamaño es positivo, se reserva la memoria para el arreglo data
    if (size > 0) {
        data = new int[size];
    } else {
        // Mostrar error
        std::cout << "Error: invalid size\n";
        
        // Apuntar data a nullptr
        data = nullptr;
    }
}

// Definición del destructor de la clase DataProcessor
DataProcessor::~DataProcessor() {
    // Si data es distinto de nullptr
    if (data != nullptr) {
        delete[] data;  // Liberar la memoria de arreglo data
        data = nullptr; // Apuntar data a nullptr
    }
}

// Definición de método para rellenar el arreglo data
void DataProcessor::populateData() {
    // Si data es igual de nullptr
    if (data == nullptr) return;

    // Recorrer el arreglo y asignar a las entradas el índice multiplicado por 10
    for (int i = 0; i < size; ++i) {
        data[i] = i * 10;
    }
}

// Definición del método para calcular la suma de los elementos de data
int DataProcessor::calculateSum() {
    // Si data es igual a nullptr, se retorna 0
    if (data == nullptr) return 0;

    int sum = 0; // Suma total

    // Recorrer el arreglo data y agregar cada índice a sum
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum;
}

// Definición de método para calcular el promedio de los elementos de data
double DataProcessor::calculateAverage() {
    // Si data es igual a nullptr o el tamaño es menor que 0, se retorna 0
    if (data == nullptr || size < 0) return 0.0;

    // Retornar el cálculo del promedio
    return static_cast<double>(calculateSum()) / size; 
}

// Definición de método para realizar un proceso concurrente de 2 hilos
void DataProcessor::concurrentProcess() {
    // Si data es igual a nullptr
    if (data == nullptr) return;

    // Declarar dos hilos que ejecuten el método processData de forma concurrente
    std::thread t1(&DataProcessor::processData, this);
    std::thread t2(&DataProcessor::processData, this);

    // Esperar a que ambos hilos terminen su ejecución
    t1.join();
    t2.join();
}

// Definición de método para imprimir los elementos del arreglo
void DataProcessor::printData() {
    // Si data es igual a nullptr
    if (data == nullptr) return;

    // Imprimir el contenido de cada índice del arreglo
    for (int i = 0; i < size; i++) {
        std::cout << "Data[" << i << "] = " << data[i] << std::endl;
    }
}

// Definición de método para procesar los datos
void DataProcessor::processData() {
    // Si data es igual a nullptr
    if (data == nullptr) return;

    // Recorrer el arreglo
    for (int i = 0; i < size; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Proteger el acceso
        data[i] *= 2; // Duplicar entrada
    }
}