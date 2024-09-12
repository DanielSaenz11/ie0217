/**
 * Set: Contenedor asociativo
 * 
 * No permite la repetición de elementos y el orden no depende de cuándo fue insertado
 * Su implementación garantiza que los elementos están ordenados de forma ascendente
 */

#include <iostream>
#include <set> // set container

using namespace std;

// Funcion main(): Punto de entrada de ejecución del programa
int main() {
    // Declaración de set tipo entero
    set<int> numbers = {1, 100, 10, 70, 100};

    // Imprimir elementos del set
    cout << "Numbers are ";
    for (auto &num : numbers) {
        cout << num << ", ";
    }
    cout << endl; // Salto de linea al final

    return 0;
}