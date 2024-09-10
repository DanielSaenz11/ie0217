/**
 * Iteradores bidireccionales: Permite la iteración hacia adelante y hacia atrás.
 * 
 * Iterar hacia adelante: ++
 * Iterar hacia atrás: --
 * Operador de desreferencia: *
 * Leer y escribir miembros: ->
 * 
 * Ejemplos: list, multiset, map, multimap
 */

#include <iostream>
#include <list> // Contenedor list

using namespace std;

// Función main(): Punto de entrada de ejecución del programa
int main() {
    // Declaración de list tipo integer
    list<int> nums {1, 2, 3, 4, 5};

    // Inicializar iterador al inicio de la lista
    list<int>::iterator itr = nums.begin();

    cout << "Moving forward: " << endl;

    // Mostrar elementos de la lista desde el inicio al final (forward)
    while (itr != nums.end()) {
        cout << *itr << ", "; // Desreferenciar valor del iterador e imprimirlo

        // Mover iterador al siguiente elemento
        itr++;
    }

    cout << endl << "Moving backward: " << endl;

    // Mostrar elementos de la lista en orden inverso
    while (itr != nums.begin()) {
        // Se recorre mientras no haya llegado al inicio
        if (itr != nums.end()) {
            // Si es distinto del end()
            cout << *itr << ", "; // Desreferenciar iterador
        }

        // Mover el iterador en una posición hacia atrás
        itr--;
    }

    // Imprimir primer elemento
    cout << *itr << endl;

    return 0;
}