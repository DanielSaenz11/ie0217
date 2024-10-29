/*
Programa que contiene errores demostrativos
NO DEBE SER COMPILADO
*/

#include <iostream>

int main() {
    // Error de sintaxis: Falta un punto y coma
    std::cout << "Iniciando el programa" << std::endl

    int divisor = 0;

    // Error en tiempo de ejecución (run-time error): División por 0
    int resultado = 10 / 0;

    int arreglo[5] = {1, 2, 3, 4, 5};
    int suma = 0;

    // Error lógico: La condición del bucle debería ser i < 5, entonces se sale del rango del arreglo
    for (int i = 0; i <= 5; ++i) {
        suma += arreglo[i];
    }

    std::cout << "Suma de los elementos del arreglo: " << suma << std::endl;

    return 0;
}