/*
Programa utilizado para probar la herramienta de debugging Valgrind
*/

#include <iostream>

void funcion1() {
    int* p = new int[10]; // Pérdida de memoria: No se libera la memoria reservada
    
    std::cout << p[0] << std::endl; // Uso de memoria no inicializado

    int array[5];
    array[5] = 10; // Acceso fuera de los límites del arreglo
}

int main() {
    funcion1(); // Llamada de la función

    return 0;
}