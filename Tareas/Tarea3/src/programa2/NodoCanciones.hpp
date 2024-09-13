#ifndef NODOCANCIONES_HPP
#define NODOCANCIONES_HPP

#include "Cancion.hpp"

struct Nodo {
    Cancion cancion;
    Nodo *siguiente;

    // Constructor
    Nodo(const Cancion &cancion);
};

#endif // NODOLISTA_HPP