/**
 * Algoritmo Bubble Sort:
 * Recorre el arreglo varias veces, de tal forma que, realiza comparaciones
 * para intercambiar las posiciones adyacentes en el arreglo si el valor de
 * la izquierda es menor que el de la derecha (caso ascendente).
 * 
 * Complejidad temporal O(n^2)
 */

#include <iostream>
using namespace std;

// Implementación de algoritmo Bubble sort 
void bubbleSort(int array[], int size) {
    
    // For loop para recorrer cada elemento del arreglo
    // Se cambió el límite del step a (size-1) para que no se supere el límite superior al acceder a array[i+1]
    for (int step = 0; step < (size - 1); ++step) {
        // For loop para comparar los elementos del arreglo
        // Se redujo el límite a (size-step-1) para evitar accesos fuera del rango
        for (int i = 0; i < (size - step - 1); ++i) {

            // Comparar elementos contiguos. Colocar < para orden descendente 
            if (array[i] > array[i+1]) {
                // Swap de las posiciones en el arreglo
                int temp = array[i]; // Variable temporal para hacer el swap
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
}


// Funcion que imprime el arreglo
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i]; // Separa los elementos con un espacio
    }
    cout << "\n"; // Salto de línea al final
}

// Funcion main(): Punto de entrada de ejecución del programa
int main() {
    // Inicializar arreglo data
    int data[] = {-2, 45, 0, 11, -9};

    // Obtener el tamaño del arreglo data
    int size = sizeof(data) / sizeof(data[0]);

    // Ordenamiento de data
    bubbleSort(data, size);

    // Imprimir el arreglo ordenado de forma ascendente
    cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size);
}