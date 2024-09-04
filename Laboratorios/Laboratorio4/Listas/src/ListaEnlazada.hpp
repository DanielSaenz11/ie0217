#ifndef LISTAENLAZADA_HPP
#define LISTAENLAZADA_HPP

// Incluir header file con declaracion de clase Nodo
#include "Nodo.hpp"

// Libreria para manejar input/output
#include <iostream>

using namespace std;

// Declaracion de clase ListaEnlazada
class ListaEnlazada {
    // Miembro privado
    private:
        Nodo* cabeza; // Primer elemento de la lista enlazada

    public:
        // Constructor de la clase ListaEnlazada
        ListaEnlazada() : cabeza(nullptr) {}
        
        // Destructor de la clase
        ~ListaEnlazada() {
            // Recorre la lista y va liberando la memoria de cada nodo hasta llegar al final (nullptr)
            while (cabeza != nullptr) {
                Nodo* temp = cabeza;
                cabeza = cabeza->siguiente;
                delete temp;
            }
        }

        // Inserta un nodo al inicio de la lista
        void insertarInicio(int valor) {

            // Reservar memoria dinamica para nuevo nodo (puntero struct)
            Nodo* nuevoNodo = new Nodo(valor);

            // Coloca la cabeza de la siguiente como el siguiente elemento del nodo actual
            nuevoNodo->siguiente = cabeza;

            // Cambia el puntero de la cabeza al nodo creado
            cabeza = nuevoNodo;
        }

        // Inserta un nodo al final de la lista enlazada
        void insertarFinal(int valor) {

            // Reservar memoria para nuevo nodo (puntero struct)
            Nodo* nuevoNodo = new Nodo(valor);

            // Si la lista esta vacio, se agrega el nuevo nodo como primer elemento
            if (cabeza == nullptr) {
                cabeza = nuevoNodo;
            }
            else {
                // Si hay mas elementos, se recorre la lista hasta llegar al final
                Nodo* temp = cabeza;
                while (temp->siguiente != nullptr) {
                    temp = temp->siguiente; // Se cambia el valor de temp al siguiente
                }

                // Cuando se llega al final de lista, se agregar el nuevo nodo como el siguiente de temp
                temp->siguiente = nuevoNodo;
            }
        }

        // Elimina un nodo con el valor ingresado como parametro
        void eliminar(int valor) {

            // Si la lista esta vacio, se sale de la funcion
            if (cabeza == nullptr) return;

            // Si la cabeza contiene el valor
            if (cabeza->dato == valor) {

                // Almacenar temporalmente el valor de cabeza
                Nodo* temp = cabeza;

                // Se coloca la cabeza nueva al siguiente nodo
                cabeza = cabeza->siguiente;

                // Se libera la memoria de la antigua cabeza
                delete temp;

                // Salir de la funcion
                return;
            }

            // Si el valor buscado no esta en el nodo cabeza
            Nodo* temp = cabeza; // Definicion de nodo temporal para recorrer la lista

            // Mientras no se llegue al final (nullptr) y el siguiente no contenga el valor buscado
            while (temp->siguiente != nullptr && temp->siguiente->dato != valor) {
                temp = temp->siguiente; // Se cambia al siguiente nodo
            }

            // Si el siguiente nodo no es nulo, significa que se salio del while por el siguiente nodo contiene el valor buscado
            if (temp->siguiente != nullptr) {

                // Se define nodoAEliminar como el siguiente
                Nodo* nodoAEliminar = temp->siguiente;

                // Se cambia el puntero siguiente del nodo actual al siguiente del siguiente (elimina de la lista el siguiente)
                temp->siguiente = temp->siguiente->siguiente;

                // Liberar memoria de nodo eliminado
                delete nodoAEliminar;
            }
        }

        // Funcion que imprime toda la lista enlazada
        void imprimir() const {

            // Definicion de nodo para recorrer la lista (inicia en cabeza)
            Nodo* temp = cabeza;

            // Recorrer la lista (hasta que se encuentre un nullptr -> final)
            while (temp != nullptr) {
                // Imprime el dato del nodo y una flecha
                std::cout << temp->dato << " -> ";

                // Cambia el nodo al siguiente
                temp = temp->siguiente;
            }
            // Al final se imprime null para indicar que se termino el recorrido de la lista
            std::cout << "null" << std::endl;
        }

        // Busca un nodo con un valor (determina si se encuentra o no)
        bool buscar(int valor) const {
            
            // Declaracion de nodo temp para recorrer la lista
            Nodo* temp = cabeza;

            // Loop para cambiar al siguiente nodo hasta que se encuentre un nullptr -> final
            while (temp != nullptr) {

                // Si el nodo contiene el dato buscado, retorna true
                if (temp->dato == valor) return true;
                
                // Si no se encontro el valor, se cambia al siguiente
                temp = temp->siguiente;
            }
            // Si se termina el recorrido de la lista y no se encontro, retorna false -> no se encuentra
            return false;
        }
    };

#endif
