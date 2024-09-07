/**
 * Algoritmo SelectionSort:
 * Se busca el valor mínimo y se coloca al inicio del arreglo. Luego, se busca el segundo mínimo
 * y se coloca en el índice 1 y así sucesivamente.
 * 
 * Se analizan subarreglos desordenados.
 * 
 * Complejidad temporal: O(n^2)
 */

#include <iostream>
using namespace std;

// Función para hacer swap de dos variables
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcion que imprime el arreglo
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " "; // Separa los elementos con un espacio
    }
    cout << endl; // Salto de línea al final
}

// Implementación de algoritmo de ordenamiento SelectionSort
void selectionSort(int array[], int size) {

    // Loop para recorrer el arreglo
    for (int step = 0; step < (size - 1); step++) {
        
        // Índice mínimo del valor mínimo de los elementos entre step y el final de arreglo
        int min_idx = step;

        // Recorrer el arreglo desde el índice step+1 hasta el final del arreglo
        for (int i = step + 1; i < size; i++) {

            // Si un elemento del arreglo posterior a step+1 es mayor que el elemento en el índice min_idx
            if (array[i] < array[min_idx]) min_idx = i;
        }

        // Swap del valor mínimo encontrado y el valor en el índice step
        swap(&array[min_idx], &array[step]);
    }
}

// Función main: Punto de entrada del programa
int main() {
    // Declaración del array data
    int data[] = {20, 12, 10, 15, 2};

    // Tamaño del arreglo
    int size = sizeof(data) / sizeof(data[0]);
    
    // Llamado de función de ordenamiento
    selectionSort(data, size);

    // Imprimir arreglo ordenado
    cout << "Sorted array in Ascending Order:\n";
    printArray(data, size);

    return 0;
}