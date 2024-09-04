#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP

// Declaracion de struct NodoArbol
struct NodoArbol {
    int dato; // Dato almacenado en el nodo
    NodoArbol* izquierdo; // Nodo izquierdo del nodo del arbol actual
    NodoArbol* derecho; // Nodo derecho del nodo del arbol actual

    // Constructor del struct NodoArbol
    NodoArbol(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {}
};

#endif