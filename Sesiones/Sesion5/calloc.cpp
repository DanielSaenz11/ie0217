/**
 * Funcion calloc():
 * Reservar la memoria e inicializarla en 0
 */

#include <iostream>
#include <cstdlib> // calloc() y free()

using namespace std;

int main() {
    // Declaracion de puntero ptr
    int *ptr;

    // Asignarle al puntero la memoria reservada con calloc() -> Inicializada en 0
    ptr = (int*)calloc(5, sizeof(int)); // data_type *varName = (data_type*)calloc(n_elements, sizeof(data_type))

    // Pointer guard: Asegurarse que el puntero no sea nulo -> Error al reservar la memoria
    if (!ptr) {
        cout << "Memory Allocation Failed";
        exit(1); // Salir del programa
    }

    cout << "Initializing values..." << endl << endl;

    // Modificar valores de los elementos reservados con calloc()    
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 2 + 1;
    }

    // Imprimir los valores inicializados
    cout << "Initialized values" << endl;
    for (int i = 0; i < 5; i++) {
        /* ptr[i] and *(ptr+i) pueden ser usados de igual forma */
        cout << *(ptr + i) << endl;
    }

    // Liberar la memoria dinamica reservada con calloc()
    free(ptr);

    return 0;
}