/**
 * Vector: Contenedor de secuencia
 * 
 * Permite almacenar elementos a los que se puede acceder en orden
 * secuencial.
 */

#include <iostream>
#include <vector> // vector container

using namespace std;

// Funcion main(): Punto de entrada de ejecución del programa
int main() {
    // Declaracion de vector numbers de tipo entero
    vector<int> numbers = {1, 100, 10, 70, 100};

    // Imprimir cada uno de los elementos del vector
    cout << "Numbers are: ";
    for (auto &num: numbers) {
        cout << num << ", ";
    }

    return 0;
}