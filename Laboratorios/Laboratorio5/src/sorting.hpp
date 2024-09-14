
// Directiva de preprocesador
#ifndef SORTING_HPP
#define SORTING_HPP

// Incluir bibliotecas
#include <iostream>
#include <vector> // std::vector
#include <algorithm>
#include <chrono> // Para medir tiempo
#include <random> // Generar numeros aleatorios

using namespace std;

// Declaración de algoritmo de ordenamiento bubble Sort
// Recibe el vector a ordenar
void bubble_sort(vector<int>& arr);

// Declaración de algoritmo de ordenamiento selection Sort
// Recibe el vector a ordenar
void selection_sort(vector<int>& arr);

// Declaración de algoritmo de ordenamiento insertion Sort
// Recibe el vector a ordenar
void insertion_sort(vector<int>& arr);

// Función para generar un vector de números aleatorios
// Recibe el tamaño del vector a crear y retorna el vector compuesto por números aleatorios
vector<int> generate_random_vector(size_t size);

#endif // SORTING_HPP