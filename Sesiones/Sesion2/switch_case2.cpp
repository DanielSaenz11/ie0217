/**
 * Ejemplo de switch_case el valor de var1
 * Note que var2 y var3 no se utilizan (por eso en codigos posteriores se comentan)
 */
#include <iostream>

int main() {
    std::cout << "Hola Mundo, estudiantes de IE0207!\n";

    // Declaracion de variables
    int var1 = 1;
    int var2 = 2;
    int var3 = 2;

    // Se compara el valor de var1 con los casos definidos
    switch (var1) {
        case 1:
            // Coincide con este caso pues var1 = 1
            std::cout << "Case 1!\n";
            break;
        case 2:
            std::cout << "Case 2!\n";
            break;
        case 3:
            std::cout << "Case 3!\n";
            break;
        
        // Caso por defecto
        default:
            break;
    }

    return 0;
}