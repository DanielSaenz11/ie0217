/**
 * Funcion malloc(): Memory Allocation
 * Utilizada para reservar memoria del heap
 * 
 * Funcion free(): Liberacion de memoria del heap
 */

#include <iostream>
#include <cstdlib> // malloc() y free()

using namespace std;

int main() {
    // Reservar memoria del tamaño de un entero a un puntero entero
    int *ptr = (int*)malloc(sizeof(int)); // data_type *varName = (data_type*)malloc(sizeof(data_type))

    // Asignar valor de 5 a la memoria reservada
    *ptr = 5;

    cout << *ptr; // Imprimir el contenido de la direccion de memoria que apunta el pointer

    // Correccion: Liberar la memoria reservada con el malloc
    free(ptr);

    return 0;
}