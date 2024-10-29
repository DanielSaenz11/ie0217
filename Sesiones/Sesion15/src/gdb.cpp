/*
Programa para utilizar gdb como herramienta de debugging
Contiene el error de dividir por 0
*/

#include <iostream>

void funcion1() {
    int a = 5; // Numerador es 5
    int b = 0; // Denominador es 0
    int c = a / b; // Error de división por 0
    std::cout << "Resultado: " << c << std::endl;
}

int main() {
    std::cout << "Iniciando el programa" << std::endl;
    funcion1(); // Llamada de la funcion
    std::cout << "Finalizando el programa" << std::endl;
    return 0;
}
