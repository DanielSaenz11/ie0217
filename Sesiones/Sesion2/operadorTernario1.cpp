/**
 * Operador ternario: [Condicion] ? valorTrue : valorFalse
 */

#include <iostream>

int main() {
    std::cout << "Hola Mundo, estudiantes de IE0207!\n";

    // Declaracion de variables
    int var1 = 0;
    int var2;

    /**
     * Se evalua si var1 tiene el valor de 0
     * Caso True: var2 = 15 
     * Caso False: var2 = 27
     */
    var2 = (var1 == 0) ? 15 : 27; // Uso de operador ternario

    std::cout << "var2: \n" << var2 << ""; // Imprimir el valor de var2

    return 0;

}