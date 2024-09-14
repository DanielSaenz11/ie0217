
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
void bubble_sort(vector<int>& arr);

// Declaración de algoritmo de ordenamiento selection Sort
void selection_sort(vector<int>& arr);

// Declaración de algoritmo de ordenamiento insertion Sort
void insertion_sort(vector<int>& arr);

// Función para generar un vector de números aleatorios
vector<int> generate_random_vector(size_t size);

#endif // SORTING_HPP