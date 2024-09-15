/**
 * @file NodoABB.cpp
 * @brief Archivo que contiene la implementación del constructor struct Nodo que componen el árbol binario de búsqueda.
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

#include "NodoABB.hpp"

// Definición del constructor del struct Nodo
Nodo::Nodo(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {}