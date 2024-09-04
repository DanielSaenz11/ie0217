
#ifndef NODO_HPP
#define NODO_HPP

// Declaracion de struct Nodo
struct Nodo {
    int dato; // Dato que contiene el objeto 
    Nodo* siguiente; // Puntero al nodo siguiente en la lista enlazada
    
    // Constructor del struct
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

#endif