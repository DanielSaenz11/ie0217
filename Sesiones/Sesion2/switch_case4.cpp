/**
 * Uso de mismo codigo para varios case
 * 
 * El codigo que imprime Case final! funciona para el case 2 y case 3
 */

#include <iostream>

int main() {
    std::cout << "Hola Mundo, estudiantes de IE0207!\n";

    // Declaracion de variables
    int var1 = 3;
    // int var2 = 2;
    // int var3 = 2;

    switch (var1) {
        case 1:
            std::cout << "Case 1!\n";
            break;
        case 2:
        case 3:
            // Se ejecuta este codigo para var1 = 3
            std::cout << "Case Final!\n";
            break;
        
        default:
            break;
    }

    return 0;
}