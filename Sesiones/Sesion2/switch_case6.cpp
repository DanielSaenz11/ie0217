/**
 * Cuando no hay coincidencia con los casos establecidos, se establece el caso default
 * que se ejecuta de forma predeterminada para el resto de valores
 */
#include <iostream>

int main() {
    std::cout << "Hola Mundo, estudiantes de IE0207!\n";

    // Declaracion de variables
    int var1 = 52;
    // int var2 = 2;
    // int var3 = 2;

    switch (var1) {
        case 1:
            std::cout << "Case 1!\n";
            break;
        case 2:
        case 3:
            std::cout << "Case Final!\n";
            break;
        
        default:
            // Se ejecuta este codigo pues var1 = 52
            std::cout << "Case default!\n";
            break;
    }

    return 0;
}