/**
 * Funcion realloc(): Re-allocate memory
 * Cambiar el tamano de la memoria reservado previamente
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // Declaracion de punteros
    float *ptr, *new_ptr;

    // Reservar memoria a ptr -> 5 floats
    ptr = (float*)malloc(5 * sizeof(float));

    // Verificar que se haya reservado correctamente
    if (ptr == NULL) {
        cout << "Memory Allocation Failed";
        exit(1); // Salir del programa
    }

    /* Inicializando bloque de memoria */
    for (int i = 0; i < 10; i++) {
        ptr[i] = i * 1.5;
    }

    /* Reallocating memoria */
    new_ptr = (float*)realloc(ptr, 10 * sizeof(float)); // data_type *varName = (data_type*)realloc(ptr_to_previous, newSize)

    // Verificar que se haya reservado correctamente
    if (new_ptr == NULL) {
        cout << "Memory Re-Allocating Failed";
        exit(1);
    }

    /* Inicializando bloque de memoria re-allocated */
    for (int i = 5; i < 10; i++) {
        // inicio en 5 porque los anteriores ya fueron asignados previamente
        new_ptr[i] = i * 2.5;
    }

    cout << "Printing values" << endl;

    // Imprimir todos el contenido de toda la memoria reservada
    for (int i = 0; i < 10; i++) {
        cout << new_ptr[i] << endl;
    }

    // Liberacion de la memoria del heap
    free(new_ptr);

    return 0;
}