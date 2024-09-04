#ifndef ARBOLBINARIOBUSQUEDA_HPP
#define ARBOLBINARIOBUSQUEDA_HPP

// Incluir header file con la definicion del struct NodoArbol
#include "NodoArbol.hpp"

// Libreria para input/output
#include <iostream>

// Libreria para algoritmos
#include <algorithm>

// Declaracion de clase ArbolBinarioBusqueda
class ArbolBinarioBusqueda {
    // Miembros privados
    private:
        NodoArbol* raiz; // Puntero a la raiz del arbol

        // Insertar nodo
        void insertarNodo(NodoArbol*& nodo, int valor) {
            
            // Si puntero esta vacio (nullptr), se asigna al nuevo nodo creado en esa posicion
            if (nodo == nullptr) {
                nodo = new NodoArbol(valor); // Reservacion con memoria dinamica
            }
            // Si el valor a colocar en el arbol es menor al dato en el nodo
            else if (valor < nodo->dato) {
                // Se llama recursivamente la funcion, hasta caer en el caso a crear el nodo en su posicion correcta
                insertarNodo(nodo->izquierdo, valor);
            }
            else {
                // Cae en el caso que se debe colocar en la derecha (llamada recursiva con el nodo derecho)
                insertarNodo(nodo->derecho, valor);
            }
        }

        // Recorrido en preorden del arbol: raiz -> izquierdo -> derecho
        void preOrden(NodoArbol* nodo) const {
            // Si el nodo no es un puntero nulo
            if (nodo != nullptr) {
                std::cout << nodo->dato << " "; // Raiz

                // Llamadas recursivas de preOrden()
                preOrden(nodo->izquierdo); // Izquierda
                preOrden(nodo->derecho); // Derecha
            }
        }

        // Recorrido en orden del arbol: izquierdo -> raiz -> derecho
        void inOrden(NodoArbol* nodo) const {
            // Si el nodo no es un puntero nulo
            if (nodo != nullptr) {
                // Llamadas recursivas para imprimir todo el arbol
                
                inOrden(nodo->izquierdo); // Lado izquierdo
                std::cout << nodo->dato << " "; // Raiz
                inOrden(nodo->derecho); // Lado derecho
            }
        }

        // Recorrido en post-orden del arbol: izquierdo -> derecho -> raiz
        void postOrden(NodoArbol* nodo) const {
            if (nodo != nullptr) {
                postOrden(nodo->izquierdo);
                postOrden(nodo->derecho);
                std::cout << nodo->dato << " ";
            }
        }

        // Busca un nodo con un valor especifico
        bool buscarNodo(NodoArbol* nodo, int valor) const {
            if (nodo == nullptr) return false; // Si es nulo, retorna false -> vacio

            if (nodo->dato == valor) return true; // Si el nodo raiz contiene el dato de interes, retorna true

            // Si el valor buscado es menor, tiene que buscar por el lado izquierdo -> Llamada recursiva por la izquierda
            if (valor < nodo->dato) return buscarNodo(nodo->izquierdo, valor);

            // Si no fue ninguno de los casos anteriores, el valor buscado es mayor -> Llamada recursiva por el lado derecho
            return buscarNodo(nodo->derecho, valor);
        }

        // Calcular la altura del arbol
        int altura(NodoArbol* nodo) const {
            // Si esta vacio, retorna 0 porque no tiene altura -> Se llego al final de esa rama
            if (nodo == nullptr) return 0;

            // Maximo entre la llamada recursiva del subarbol izquierdo y derecho
            return 1 + std::max(altura(nodo->izquierdo), altura(nodo->derecho)); // Se le suma 1 para añadir la altura actual
        }

        // Verificar si el arbol esta balanceado o no (alturas no se exceden en 1)
        bool estaBalanceado(NodoArbol* nodo) const {


            if (nodo == nullptr) return true;

            int alturaIzquierda = altura(nodo->izquierdo); // Altura del subarbol izquierdo
            int alturaDerecha = altura(nodo->derecho); // Altura del subarbol derecho

            /* 
            Retorna el valor absoluto de la resta de la altura izquierda y derecha -> que no excedan 1
            llamada recursiva para determinar si el subarbol izquierdo y derecho estan balanceados
            */
            return std::abs(alturaIzquierda - alturaDerecha) <= 1 &&
                estaBalanceado(nodo->izquierdo) &&
                estaBalanceado(nodo->derecho);
        }

    // Miembros publicos -> No requieren raiz pues raiz es privado
    public:
        // Constructor de la clase ArbolBinarioBusqueda
        ArbolBinarioBusqueda() : raiz(nullptr) {}

        // Funcion miembro que llama a la funcion insertarNodo()
        void insertar(int valor) {
            insertarNodo(raiz, valor);
        }

        // Funcion miembro que llama a la funcion preOrder()
        void preOrden() const {
            preOrden(raiz);
            std::cout << std::endl;
        }

        // Funcion miembro que llama a la funcion inOrder()
        void inOrden() const {
            inOrden(raiz);
            std::cout << std::endl;
        }

        // Funcion miembro que llama a la funcion postOrder()
        void postOrden() const {
            postOrden(raiz);
            std::cout << std::endl;
        }

        // Funcion miembro que llama a la funcion buscarNodo()
        bool buscar(int valor) const {
            return buscarNodo(raiz, valor);
        }

        // Funcion miembro que llama a la funcion altura
        int altura() const {
            return altura(raiz);
        }

        // Funcion miembro que llama a la funcion estaBalanceado()
        bool estaBalanceado() const {
            return estaBalanceado(raiz);
        }
};

#endif
