#ifndef NODOABB_HPP
#define NODOABB_HPP

// Declaracion de struct Nodo
struct Nodo {
    int dato; // Dato almacenado en el nodo
    Nodo* izquierdo; // Nodo izquierdo del nodo del arbol actual
    Nodo* derecho; // Nodo derecho del nodo del arbol actual

    // Constructor del struct Nodo
    Nodo(int valor);
};

#endif