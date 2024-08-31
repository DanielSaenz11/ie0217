/**
 * Tipos de memoria donde se guardan los datos
 * 
 * Text: Almacena el codigo donde se esta ejecutando
 * Data: Almacena variables globales, inicializadas y no inicializadas
 * Heap: Memoria dinamica para que quien la programe la asigne
 * Stack: Almacena variables globales
 */

#include <iostream>

/* Se almacena en el segmento de data*/
int globalVariable = 42;

int main() {
    /* Se almacena en el stack */
    int stackVariable = 10;

    /* Se almacena en el heap */
    int* heapVariable = new int(20); // new: reservar memoria del heap, retorna una direccion

    // Imprimir los valores de las variables
    std::cout << "Valor de globalVariable: " << globalVariable << std::endl;
    std::cout << "Valor de stackVariable: " << stackVariable << std::endl;
    std::cout << "Valor de heapVariable: " << heapVariable << std::endl;

    /* Liberar la memoria  asignada en el heap */
    delete heapVariable;

    return 0;
}