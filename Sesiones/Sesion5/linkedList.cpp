/**
 * Implementacion de lista enlazada
 * Un nodo contiene el puntero al siguiente nodo en la lista enlazada
 */

//#include <bits/stdc++.h> // Incluye bibliotecas estandar de C++, pero no es necesario para la implementacion actual
#include <iostream>
using namespace std;

// Declaracion de clase Node
class Node {
    public:
        int value;   // Valor del nodo
        Node* next;  // Siguiente nodo de la lista
};

int main() {

    Node* head; // Nodo cabeza de la lista enlazada (para recorrerla)
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    // Reservar memoria para los nodos en el heap
    one = new Node();
    two = new Node();
    three = new Node();

    // Asignar valores a nodos
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Conectar nodos: 1 -> 2 -> 3 -> NULL
    one->next = two;
    two->next = three;
    three->next = NULL;

    // Imprimir la lista enlazada por valor
    head = one;
    while (head != NULL) {
        cout << head->value << "->"; // Se agrego -> para mejor visualizacion del contenido de los nodos
        head =  head->next;
    }

    cout << "NULL" << endl; // Se agrego un salto de linea al final y la palabra NULL para indicar que se termino

    // Error: No se libera la memoria dinamica
    delete one;
    delete two;
    delete three;

    return 0;
}
