/**
 * Algoritmo QuickSort
 * 
 * Se selecciona un pivote y se colocan el resto de elementos del array antes y después de este valor
 * dependiendo si son mayores o menores. Se llama recursivamente la función que realiza esto hasta
 * obtener el arreglo ordenado
 * 
 * Complejidad temporal promedio: O(nlog(n))
 * Peor complejidad temporal: O(n^2)
 */

#include <iostream>
using namespace std;

// Función para intercambiar dos elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función que particiona el array en dos subarrays
int particion(int array[], int bajo, int alto) {
    int pivote = array[alto];  // Selecciona el último elemento del arreglo como pivote
    int i = (bajo - 1);  // Índice del elemento más pequeño

    // Recorrer el subarreglo
    for (int j = bajo; j < alto; j++) {
        // Si el elemento actual es menor o igual que el pivote
        if (array[j] <= pivote) {
            i++;  // Incrementa el índice de elementos más pequeños que el pivote
            swap(array[i], array[j]); // swap de array[i] y array[j]
        }
    }
    swap(array[i + 1], array[alto]); // Colocar el pivote por encima de los numeros que son menores que él
    return (i + 1); // Índice del pivote
}

// Función recursiva que aplica el algoritmo de Quicksort
void quicksort(int array[], int bajo, int alto) {
    if (bajo < alto) {
        // Índice del pivote, el array está dividido en dos subarrays
        int pivote = particion(array, bajo, alto);

        // Aplica quicksort en los subarrays
        quicksort(array, bajo, pivote - 1);  // Lado izquierdo
        quicksort(array, pivote + 1, alto);  // Lado derecho
    }
}

// Función para imprimir el array
void imprimirArray(int array[], int tamano) {
    // Recorre los elementos del array
    for (int i = 0; i < tamano; i++)
        cout << array[i] << " "; // Imprime los elementos separados por un espacio
    cout << endl;
}

// Función main(): Punto de entrada del programa
int main() {
    // Declaración de array
    int array[] = {10, 80, 30, 90, 40, 50, 70};

    // Cálculo del tamaño del array
    int tamano = sizeof(array) / sizeof(array[0]);

    // Llamado del algoritmo de ordenamiento
    quicksort(array, 0, tamano - 1);

    // Imprimir arreglo ordenado resultante
    cout << "Array ordenado: ";
    imprimirArray(array, tamano);

    return 0;
}
