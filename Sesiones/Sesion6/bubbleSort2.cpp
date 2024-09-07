/**
 *
 * Algoritmo Bubble Sort Optimizado:
 * Recorre el arreglo varias veces, de tal forma que, realiza comparaciones
 * para intercambiar las posiciones adyacentes en el arreglo si el valor de
 * la izquierda es menor que el de la derecha (caso ascendente).
 * 
 * Se añadió variable swapped para terminar el loop antes si se dejaron de
 * realizar cambios, lo cual indica que el arreglo está ordenado
 * 
 * Complejidad temporal O(n^2)
 */


#include <iostream>
using namespace std;

// Implementación de algoritmo BubbleSort optimizado
void bubbleSort(int array[], int size) {

    // Loop para recorrer todos los elementos del array
    for (int step = 0; step < (size-1); ++step) {
        
        // Revisar si el swap ocurre
        int swapped = 0;

        // Loop para comparar dos elementos contiguos del arreglo
        for (int i = 0; i < (size - step - 1); ++i) {

            // Comparar dos elementos del array. Colocar < para orden descendente 
            if (array[i] > array[i+1]) {

                // Si el elemento anterior es mayor, se hace swap
                int temp = array[i]; // Variable temporal para el swap
                array[i] = array[i+1];
                array[i+1] = temp;

                // Indicar que se realizó el cambio
                swapped = 1; 
            }
        }
        // Si no se hizo cambio, significa que el arreglo está ordenado
        if (swapped == 0) {
            // Se sale del loop
            break;
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
