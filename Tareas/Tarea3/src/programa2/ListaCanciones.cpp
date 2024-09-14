/**
 * @file ListaCanciones.cpp
 * @brief Archivo que contiene la definición de las funciones miembro de la clase ListaCanciones.
 * 
 * @details En este source file se implementan las funciones declaradas en el header file ListaCanciones.hpp, en donde
 * se colocaron las funciones propias de la lista enlazada que representa la clase.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 14/09/2024
 */

#include <iostream>
#include "ListaCanciones.hpp" // Header file que contiene la declaración de la clase ListaCanciones

using namespace std;

// Definición del constructor de la clase ListaCanciones: Inicializa el nodo cabeza como nullptr
ListaCanciones::ListaCanciones() : cabeza(nullptr) {}

// Definición del destructor de la clase ListaCanciones: Libera la memoria de cada nodo que compone la lista
ListaCanciones::~ListaCanciones() {
    // Recorrido de la lista
    while (cabeza) {
        Nodo *temp = cabeza;
        cabeza = cabeza->siguiente; // Cambio al siguiente
        delete temp; // Liberar memoria
    }
}

// Definición de función miembro insertarInicio()
void ListaCanciones::insertarInicio(const Cancion &cancion) {
    Nodo *nuevoNodo = new Nodo(cancion); // Asignar memoria del nuevo nodo
    nuevoNodo->siguiente = cabeza; // Colocar al inicio de la lista
    cabeza = nuevoNodo; // Cambio de puntero cabeza al nuevo nodo
}

// Definición de función miembro insertarFinal()
void ListaCanciones::insertarFinal(const Cancion &cancion) {
    Nodo *nuevoNodo = new Nodo(cancion); // Asignar memoria del nuevo nodo

    // Si la lista está vacía, se coloca como la cabeza
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

// Definición de función miembro insertarPosicion()
void ListaCanciones::insertarPosicion(const Cancion &cancion, int posicion) {
    // Si la posición es al inicio de la lista
    if (posicion == 0) {
        insertarInicio(cancion); // Se inserta al inicio
        return;
    }

    Nodo *nuevoNodo = new Nodo(cancion); // Asignar memoria del nuevo nodo
    Nodo *actual = cabeza; // Nodo para recorrer la lista desde el inicio

    // Recorrido de la lista hasta la posicion indicada
    for (int i = 0; actual != nullptr && i < posicion - 1; i++) {
        actual = actual->siguiente;
    }

    // Si la posición es válida, se inserta el nodo en esa posición
    if (actual) {
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
    else {
        // Posición no válida, se libera la memoria asignada
        delete nuevoNodo;
        cout << "Error: Posición no válida." << endl;
    }
}

// Definición de función miembro eliminarCancion()
void ListaCanciones::eliminarCancion(const string &nombre) {
    Nodo *actual = cabeza; // Nodo para recorrer la lista
    Nodo *anterior = nullptr; // Rastreo del nodo anterior al nodo a eliminar

    // Recorrido de la lista para buscar la canción
    while (actual && actual->cancion.getNombre() != nombre) {
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si el nodo actual es distinto de nullptr
    if (actual) {
        // Si anterior es válido, se ajustan las referencias de los elementos anterior y siguiente
        if (anterior) {
            anterior->siguiente = actual->siguiente;
        }

        // Si anterior es nullptr -> actual es el primer elemento
        else {
            cabeza = actual->siguiente;
        }

        // Liberar memoria del nodo a eliminar
        delete actual;

        cout << "Se eliminó la canción " << nombre << endl;
    }
    else {
        cout << "La canción " << nombre << "no existe" << endl;
    }
}

// Definición de función miembro modificarCancion()
void ListaCanciones::modificarCancion(const string &nombre) {
    Nodo *nodo = buscarCancion(nombre); // Buscar cancion por nombre

    // Si la canción existe
    if (nodo) {

        // Declaración de nuevos elementos de la canción
        string nuevoNombre, nuevoArtista;
        double nuevaDuracion;

        /* Input de nuevos elementos */

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

// Definición de función miembro buscarCancion()
Nodo* ListaCanciones::buscarCancion(const string &nombre) const {
    Nodo *actual = cabeza; // Declaración de nodo para recorrer la lista

    // Recorrido de la lista hasta encontrar un nombre que coincida
    while (actual && actual->cancion.getNombre() != nombre) {
        actual = actual->siguiente;
    }

    return actual;
}

// Definición de función miembro imprimirLista()
void ListaCanciones::imprimirLista() const {
    Nodo *actual = cabeza; // Declaración de nodo para recorrer la lista

    // Recorrido de la lista completa
    while (actual) {
        // Imprimir atributos de las canciones con formato solicitado
        cout << actual->cancion.getNombre() << " - " << actual->cancion.getArtista()
             << " (" << actual->cancion.getDuracion() << " min)" << endl;
        
        actual = actual->siguiente; // Cambio a la siguiente canción de la lista
    }
}
