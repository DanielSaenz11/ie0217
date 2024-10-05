

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

/**
 * @brief Implementación del algoritmo Insertion Sort.
 *
 * Ordena un vector construyendo gradualmente una porción ordenada y insertando elementos en su posición correcta.
 *
 * @tparam T Tipo de datos almacenados en el vector.
 * @param arr Referencia al vector que se va a ordenar.
 * @return void
 */
template <typename T>
void insertionSort(vector<T>& arr) {

    // Recorrido del arreglo desde el índice 1 hasta el final
    for (size_t i = 1; i < arr.size(); i++) {
        // Valor de va a ser insertado en su posición correcta dentro del arreglo ordenado
        T key = arr[i];

        // Índice para insertar a key en el arreglo ordenado (izquierda)
        int j = i - 1;

        // Insertar key en su valor correspondiente en el arreglo ordenado
        while (j >= 0 && arr[j] > key) {

            // Si key es menor que array[j], se mueve array[j] a la siguiente posición
            arr[j + 1] = arr[j];
            j--; // Disminuir j
        }

        // Cuando se sale del loop, se encontró la posición correcta
        arr[j + 1] = key; 
    }
}

/**
 * @brief Función auxiliar para Quick Sort que divide el vector.
 *
 * Reorganiza el vector de forma que los elementos menores o iguales al pivote estén a la izquierda y los
 * mayores a la derecha.
 *
 * @tparam T Tipo de datos almacenados en el vector.
 * @param arr Referencia al vector a particionar.
 * @param low Índice inicial del segmento a particionar.
 * @param high Índice final del segmento a particionar.
 * @return Índice del pivote después de la partición.
 */
template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high]; // Pivote
    int i = low -1; // Índice del elemento más pequeño
    for (int j = low; j <= high -1; ++j){
        if (arr[j] <= pivot){
            ++i;
            std::swap(arr[i], arr[j]); // Cambio de variables
        }
    }
    std::swap(arr[i+1], arr[high]);
    return (i+1);
}

/**
 * @brief Implementación recursiva del algoritmo Quick Sort.
 *
 * Ordena un segmento del vector utilizando Quick Sort de forma recursiva.
 *
 * @tparam T Tipo de datos almacenados en el vector.
 * @param arr Referencia al vector que se va a ordenar.
 * @param low Índice inicial del segmento a ordenar.
 * @param high Índice final del segmento a ordenar.
 * @return void
 */
template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high){
        // Realiza la partición y llama recursivamente para las dos mitades nuevas
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi -1);
        quickSort(arr, pi +1, high);
    }
}

/**
 * @brief Implementación del algoritmo Quick Sort.
 *
 * Ordena un vector completo utilizando Quick Sort.
 *
 * @tparam T Tipo de datos almacenados en el vector.
 * @param arr Referencia al vector que se va a ordenar.
 * @return void
 */
template <typename T>
void quickSortWrapper(std::vector<T>& arr) {
    quickSort(arr, 0, arr.size() -1); // Llamada de quicksort con argumentos iniciales
}



/**
 * @brief Genera un vector de números aleatorios.
 *
 * Crea y devuelve un vector del tamaño especificado, lleno de números aleatorios en un rango definido.
 *
 * @tparam T Tipo de datos almacenados en el vector.
 * @param size Tamaño del vector a generar.
 * @return Un vector de tamaño 'size' con números aleatorios.
 */
template <typename T>
vector<T> generateRandomVector(size_t size) {
    
    // Declaración del vector que contiene los datos aleatorios
    vector<T> vec(size);

    // Configuración del generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10000); // Rango de generación de números aleatorios

    // Agregar elementos aleatorios al vector
    for (size_t i = 0; i < size; ++i) {
        vec[i] = dist(gen);
    }
    return vec; // Retornar el vector
}




#endif // SORTING_HPP