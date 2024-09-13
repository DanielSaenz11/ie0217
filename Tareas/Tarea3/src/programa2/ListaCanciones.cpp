#include <iostream>
#include "ListaCanciones.hpp"

using namespace std;

// Definición del constructor
ListaCanciones::ListaCanciones() : cabeza(nullptr) {}

ListaCanciones::~ListaCanciones() {
    while (cabeza) {
        Nodo *temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void ListaCanciones::insertarInicio(const Cancion &cancion) {
    Nodo *nuevoNodo = new Nodo(cancion);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void ListaCanciones::insertarFinal(const Cancion &cancion) {
    Nodo *nuevoNodo = new Nodo(cancion);

    // Si la lista está vacía
    if (!cabeza) {
        cabeza = nuevoNodo;
    }
    else {
        
        // Declarar nodo para recorrer la lista enlazada
        Nodo *actual = cabeza;

        // Recorrer la lista hasta el final
        while (actual->siguiente) {
            actual = actual->siguiente;
        }

        // Agregar nuevo nodo al final
        actual->siguiente = nuevoNodo;
    }
}

void ListaCanciones::insertarPosicion(const Cancion &cancion, int posicion) {
    // Si la posición es al inicio de la lista
    if (posicion == 0) {
        insertarInicio(cancion);
        return;
    }

    Nodo *nuevoNodo = new Nodo(cancion);
    Nodo *actual = cabeza;

    // Recorrido de la lista hasta la posicion indicada
    for (int i = 0; actual != nullptr && i < posicion - 1; i++) {
        actual = actual->siguiente;
    }

    if (actual) {
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

void ListaCanciones::eliminarCancion(const string &nombre) {
    Nodo *actual = cabeza;
    Nodo *anterior = nullptr; // Rastreo del nodo anterior al nodo a eliminar

    while (actual && actual->cancion.getNombre() != nombre) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual) {
        if (anterior) {
            anterior->siguiente = actual->siguiente;
        }
        else {
            cabeza = actual->siguiente;
        }

        // Liberar memoria del nodo a eliminar
        delete actual;
    }
}

void ListaCanciones::modificarCancion(const string &nombre) {
    Nodo *nodo = buscarCancion(nombre);

    if (nodo) {
        string nuevoNombre, nuevoArtista;
        double nuevaDuracion;

        cout << "Nuevo nombre: ";
        cin >> nuevoNombre;

        cout << "Nuevo artista: ";
        cin >> nuevoArtista;

        cout << "Nueva duración: ";
        cin >> nuevaDuracion;

        // Modificar los valores de las variables miembro de la canción
        nodo->cancion.setNombre(nuevoNombre);
        nodo->cancion.setArtista(nuevoArtista);
        nodo->cancion.setDuracion(nuevaDuracion);
    }
}

Nodo* ListaCanciones::buscarCancion(const string &nombre) const {
    Nodo *actual = cabeza;

    while (actual && actual->cancion.getNombre() != nombre) {
        actual = actual->siguiente;
    }

    return actual;
}

void ListaCanciones::imprimirLista() const {
    Nodo *actual = cabeza;

    while (actual) {
        cout << actual->cancion.getNombre() << " - " << actual->cancion.getArtista()
             << " (" << actual->cancion.getDuracion() << " min)" << endl;
        
        actual = actual->siguiente;
    }
}
