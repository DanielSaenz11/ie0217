/**
 * @file NodoABB.hpp
 * @brief Archivo que contiene la declaración del struct Nodo que componen el árbol binario de búsqueda.
 * 
 * @details En este header file se incluye la declaración de los elementos del struct Nodo, que corresponden
 * al dato que guarda y un puntero al nodo izquierdo y derecho respecto al actual. Además, se declaró un constructor para 
 * crear objetos a partir del struct.
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

#ifndef NODOABB_HPP
#define NODOABB_HPP

// Declaracion de struct Nodo
struct Nodo {
    /// @brief Dato almacenado en el nodo
    int dato;

    /// @brief Nodo izquierdo del árbol actual
    Nodo* izquierdo;
    
     /// @brief Nodo derecho del nodo del arbol actual
    Nodo* derecho;

    /**
     * @brief Constructor del struct Nodo
     * 
     * Inicializa los 3 valores del struct. A partir del parámetro recibido, se asigna al dato, mientras que, los
     * punteros se inicializan como nullptr
     */
    Nodo(int valor);
};

#endif