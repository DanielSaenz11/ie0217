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
            std::cout << "Case 2!\n";
            break;
        case 3:
            // Coincide en este caso pues var1 = 3
            std::cout << "Case 3!\n";
            break;
        
        default:
            break;
    }

    return 0;
}