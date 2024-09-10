/**
 * Container adapters
 * 
 * Corresponden a un contener existente para el cual se le restringe
 * su interfaz para comportarse de cierta forma
 * 
 * Ejemplo: stack
 * Únicamente tiene las funciones push() y pop()
 * Principio FIFO
 */

#include <iostream>
#include <stack> // Container adapter stack

using namespace std;

// Funcion main(): Punto de entrada de ejecución del programa
int main() {

    // Declaración de stack numbers de tipo entero
    stack<int> numbers;

    // Agregar elementos al stack
    numbers.push(1);
    numbers.push(100);
    numbers.push(10);

    // Imprimir números del stack
    cout << "Numbers are ";

    // Se acceden los elementos al obtener el elemento top y eliminarlo
    // hasta que el stack esté vacío
    while(!numbers.empty()) {
        cout << numbers.top() << ", ";

        numbers.pop();
    }

    return 0;
}