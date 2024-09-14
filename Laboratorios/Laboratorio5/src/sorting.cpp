#include "sorting.hpp" // Header file con declaración de algortimos de sorting
using namespace std;

// Implementación de Bubble Sort
void bubble_sort(vector<int>& arr) {
    bool swapped; // Condicion de si se hizo swap de entradas

    // Primera recorrida del arreglo
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

// Implementación de Selection Sort
void selection_sort(vector<int>& arr) {

    // Recorrido del arreglo
    for (size_t i = 0; i < arr.size() - 1; i++) {
        
        // Índice mínimo
        size_t min_index = i;

        // Recorrido para comparar si hay un elemento menor que el elemento en el índice mínimo
        // Se coloca el menor elemento en la posición correcta
        for (size_t j = i + 1; j < arr.size(); j++) {
            
            // Si hay un elemento en el arreglo menor que el elemento mínimo guardado en el índice mínimo
            if (arr[j] < arr[min_index]) {
                min_index = j; // Cambio de índice mínimo
            }
        }

        // Swap de variables para acomodar el elemento mínimo en la posición adecuada
        swap(arr[i], arr[min_index]);
    }
}

// Implementación de Insertion Sort
void insertion_sort(vector<int>& arr) {

    // Recorrido del arreglo desde el índice 1 hasta el final
    for (size_t i = 1; i < arr.size(); i++) {
        // Valor de va a ser insertado en su posición correcta dentro del arreglo ordenado
        int key = arr[i];

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

// Función para generar un vector de números aleatorios
vector<int> generate_random_vector(size_t size) {
    
    // Declaración del vector que contiene los datos aleatorios
    vector<int> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10000); // Rango de generación de números aleatorios

    // Agregar elementos aleatorios al vector
    for (size_t i = 0; i < size; ++i) {
        vec[i] = dist(gen);
    }
    return vec; // Retornar el vector
}