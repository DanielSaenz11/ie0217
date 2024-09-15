/**
 * @file ABB.cpp
 * @brief Archivo que contiene la definición de las funciones miembro de la clase ABB.
 * 
 * @details En este source file se definen las funciones miembro de la clase ABB, abarca el construcor y destructor de la clase,
 * así como las funciones públicas y privadas para insertar y eliminar un nodo en el ABB, realizar el recorrido en orden, calcular
 * la altura del ABB y verificar si está balanceado.
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
#include "ABB.hpp"

using namespace std;

// Definición del constructor de la clase ABB: Inicializa el nodo raíz en nullptr
ABB::ABB() : raiz(nullptr) {}

// Definición del destructor de la clase ABB: Llama a la función recursiva destruirArbol()
ABB::~ABB() {
    destruirArbol(raiz);
}

// Definición de la función miembro pública insertar(): Llama a la función privada recursiva insertar()
void ABB::insertar(int valor) {
    raiz = insertar(raiz, valor); // Llamado de la función privada insertar()
}

// Definición de la función miembro privada insertar()
Nodo* ABB::insertar(Nodo* nodo, int valor) {
    
    // Si el árbol está vacío, se retorna el nodo para colocarlo como raíz
    if (!nodo) return (new Nodo(valor));

    // Si el valor a insertar es menor que el valor en el nodo actual, se mueve hacia el lado izquierdo
    if (valor < nodo->dato) nodo->izquierdo = insertar(nodo->izquierdo, valor);

    // Si el valor a insertar es mayor que el valor en el nodo actual, se mueve hacia el lado derecho
    else nodo->derecho = insertar(nodo->derecho, valor);

    return nodo; // Retorno del nodo a medida que se reconstruye el ABB
}

// Definición de la función miembro pública eliminar()
void ABB::eliminar(int valor) {
    raiz = eliminar(raiz, valor); // Llama la función recursiva eliminar() y asigna el retorno en la raíz
}

// Definición de la función miembro privada eliminar()
Nodo* ABB::eliminar(Nodo *nodo, int valor) {
    
    // Caso base de recursión: si el nodo es nullptr, no se encontró para eliminar
    if (!nodo) return nullptr;

    // Si el valor es menor que el nodo actual, se busca en el nodo izquierdo
    if (valor < nodo->dato) nodo->izquierdo = eliminar(nodo->izquierdo, valor);

    // Si el valor es mayor que el nodo actual, se busca en el nodo derecho
    else if (valor > nodo->dato) nodo->derecho = eliminar(nodo->derecho, valor);

    // Si se encuentra el nodo con el valor buscado
    else {
        // Caso 1: El nodo a eliminar no tiene hijo izquierdo
        if (!nodo->izquierdo) {
            Nodo *temp = nodo->derecho; // Se almacena subarbol derecho
            delete nodo; // Elimina el nodo actual
            return temp; // Retorna el subarbol derecho
        }

        // Caso 2: El nodo a eliminar no tiene hijo derecho
        if (!nodo->derecho) {
            Nodo *temp = nodo->izquierdo; // Se almacena el subarbol izquierdo
            delete nodo; // Elimina el nodo actual
            return temp; // Retorna el subarbol izquierdo
        }

        // Caso 3: El nodo tiene tanto hijo izquierdo como derecho
        Nodo *minNodo = encontrarMinimo(nodo->derecho); // Se busca el nodo mínimo en el subarbol derecho como sustituto al actual
        nodo->dato = minNodo->dato; // Se sustituye actual con el mínimo de la derecha 
        nodo->derecho = eliminar(nodo->derecho, minNodo->dato); // Eliminar el nodo mínimo en el subarbol derecho
    }

    // Retornar el nodo actual de las modificaciones
    return nodo;
}

// Definición de la función miembro privada encontrarMinimo()
Nodo* ABB::encontrarMinimo(Nodo *nodo) {

    // Recorrido a partir de un nodo hacia la izquierda hasta encontrar el valor mínimo en el subarbol
    while (nodo && nodo->izquierdo) {
        nodo = nodo->izquierdo; // Cambio al nodo izquierdo
    }

    return nodo; // Retornar el nodo mínimo
}

// Definición de la función miembro pública inOrderTraversal()
void ABB::inOrderTraversal() const {
    inOrderTraversal(raiz); // Llama a la función privada inOrderTraversal()
    cout << endl;
}

// Definición de la función miembro privada inOrderTraversal()
void ABB::inOrderTraversal(Nodo *nodo) const {
    // Si el nodo no es nulo
    if (nodo) {
        // Se recorre recursivamente hacia el subarbol izquierdo
        inOrderTraversal(nodo->izquierdo);
        cout << nodo->dato << " "; // Se imprime el dato del nodo actual
        inOrderTraversal(nodo->derecho); // Se llama recursivamente hacia el subarbol derecho
    }
}

// Definición de la función miembro pública calcularAltura()
int ABB::calcularAltura() const {
    return calcularAltura(raiz); // Llamado de la función privada calcularAltura()
}

// Definición de la función miembro privada calcularAltura()
int ABB::calcularAltura(Nodo *nodo) const {
    // Si el nodo es nulo, se indica que la altura es 0
    if (!nodo) return 0;

    // Se llama recursivamente el máximo entre la altura del subarbol izquierdo y derecho
    return 1 + max(calcularAltura(nodo->izquierdo), calcularAltura(nodo->derecho)); // Se le suma 1 para añadir la altura actual
}

// Definición de la función miembro pública estaBalanceado()
bool ABB::estaBalanceado() const {
    return estaBalanceado(raiz); // Llamado de la función privada estaBalaceado() con el nodo raiz como parámetro
}

// Definición de la función miembro privada estaBalanceada()
bool ABB::estaBalanceado(Nodo *nodo) const {
    if (nodo == nullptr) return true; // Caso base de la recursividad

    int alturaIzquierda = calcularAltura(nodo->izquierdo); // Altura del subarbol izquierdo
    int alturaDerecha = calcularAltura(nodo->derecho); // Altura del subarbol derecho

    /* 
    Retorna el valor absoluto de la resta de la altura izquierda y derecha -> que no excedan 1
    llamada recursiva para determinar si el subarbol izquierdo y derecho estan balanceados
    */
    return std::abs(alturaIzquierda - alturaDerecha) <= 1 &&
        estaBalanceado(nodo->izquierdo) &&
        estaBalanceado(nodo->derecho);
}

// Definición de la función miembro privada destruirArbol()
void ABB::destruirArbol(Nodo *nodo) {
    
    // Eliminar los nodos del arbol recursivamente
    if (nodo) {
        destruirArbol(nodo->izquierdo); // Libera la memoria del subarbol izquierdo 
        destruirArbol(nodo->derecho); // Libera la memoria del subarbol derecho
        delete nodo; // Libera la memoria del nodo actual
    }
}