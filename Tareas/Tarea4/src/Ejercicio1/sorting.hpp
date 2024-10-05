

// Directiva de preprocesador
#ifndef SORTING_HPP
#define SORTING_HPP

// Incluir bibliotecas
#include <iostream>  // I/O
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <random>    // Generar numeros aleatorios

using namespace std;

/**
 * @brief Implementación del algoritmo Bubble Sort.
 *
 * Ordena un vector comparando pares adyacentes y realizando intercambios si están en el orden incorrecto.
 *
 * @tparam T Tipo de datos almacenados en el vector.
 * @param arr Referencia al vector que se va a ordenar.
 * @return void
 */
template <typename T>
void bubbleSort(vector<T>& arr) {
    bool swapped; // Condicion de si se hizo swap de entradas

    // Primer recorrido del arreglo
    for (size_t i = 0; i < arr.size() - 1; i++) {
        swapped = false;

        // Recorrido para hacer comparaciones y swaps
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            
            // Si un elemento de la izquierda es mayor que uno de la derecha -> DESORDEN
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap de las variables
                swapped = true; // Se indica que se realizó el cambio
            }
        }

        // Si no se hizo cambio, significa que ya se ordenó el arreglo
        if (!swapped)
            break;
    }
}


/**
 * @brief Implementación del algoritmo Selection Sort.
 *
 * Ordena un vector seleccionando repetidamente el elemento mínimo y colocándolo al principio.
 *
 * @tparam T Tipo de datos almacenados en el vector.
 * @param arr Referencia al vector que se va a ordenar.
 * @return void
 */
template <typename T>
void selectionSort(vector<T>& arr) {

    // Recorrido del arreglo
    for (size_t i = 0; i < arr.size() - 1; i++) {
        
        // Índice mínimo
        size_t minIndex = i;

        // Recorrido para comparar si hay un elemento menor que el elemento en el índice mínimo
        // Se coloca el menor elemento en la posición correcta
        for (size_t j = i + 1; j < arr.size(); j++) {
            
            // Si hay un elemento en el arreglo menor que el elemento mínimo guardado en el índice mínimo
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Cambio de índice mínimo
            }
        }

        // Swap de variables para acomodar el elemento mínimo en la posición adecuada
        swap(arr[i], arr[minIndex]);
    }
}


#endif // SORTING_HPP