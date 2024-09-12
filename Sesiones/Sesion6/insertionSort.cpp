/**
 * Algoritmo InsertionSort:
 * Consiste en que toma cada elemento del arreglo y lo inserta en la posición
 * correcta en la parte ya ordenada del arreglo.
 * 
 * Divide el arreglo en una parte ordenada (izquierda) y una parte desordenada
 * (derecha).
 * 
 * Complejidad temporal: O(n^2)
 */

#include <iostream>
using namespace std;

// Funcion para imprimir el arreglo
void printArray(int array[], int size) {
    // Recorre cada elemento del arreglo
    for (int i = 0; i < size; i++) {
        cout << array[i] << " "; // Espacio entre cada elemento
    }
    cout << endl; // Salto de línea al final
}

// Implementacion del algoritmo de ordenamiento InsertionSort
void insertionSort(int array[], int size) {
    // Recorrido desde el segundo elemento hasta el final
    for (int step = 1; step < size; step++) {
        // Valor de va a ser insertado en su posición correcta dentro del arreglo ordenado
        int key = array[step];

        // Índice para insertar a key en el arreglo ordenado (izquierda)
        int j = step - 1;

        // Insertar key en su valor correspondiente en el arreglo ordenado
        while (key < array[j] && j >= 0) {
            // Se compara con los elementos de array[j] hasta array[0]

            // Si key es menor que array[j], se mueve array[j] a la siguiente posición
            array[j+1] = array[j];
            --j; // Disminuir j
        }

        // Cuando se sale del loop, se encontró la posición correcta
        array[j + 1] = key; // Insertar key en j+1 (pues al final del loop se redujo el índice)
    
    }
}

// Función main(): Punto de entrada del programa
int main() {
    // Declaración del arreglo data
    int data[] = {9, 5, 1, 4, 3};

    // Tamaño del arreglo data
    int size = sizeof(data) / sizeof(data[0]);

    // Llamado del algoritmo InsertionSort
    insertionSort(data, size);

    // Imprimir arreglo ordenado
    cout << "Sorted array in ascending order:\n";
    printArray(data, size);

    return 0;
}

