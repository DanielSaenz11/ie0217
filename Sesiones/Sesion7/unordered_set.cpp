/**
 * Unordered_set: Contenedor asociativo desordenado
 * 
 * Sin ordenador el contenedor asociativo. Implementacion de hash-tables
 */

#include <iostream>
#include <unordered_set> // unordered_set container

using namespace std;

// Funcion main(): Punto de entrada de ejecución del programa
int main() {
    // Inicialización de unordered_set numbers de tipo entero
    unordered_set<int> numbers = {1, 100, 10, 70, 100};

    // Imprimir elementos de numbers
    cout << "Numbers are ";
    for (auto &num : numbers) {
        cout << num << ", "; // Separados por comas
    }

    return 0;
}