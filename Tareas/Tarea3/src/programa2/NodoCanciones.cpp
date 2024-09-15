/**
 * @file NodoCanciones.cpp
 * @brief Archivo que contiene la definición del constructor del struct Nodo para la implementación de la 
 * lista de canciones.
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

#include "NodoCanciones.hpp" // Declaración de struct Nodo

/*
 Definición del constructor del struct Nodo: 
 Recibe una canción e inicializa el valor del puntero al siguiente nodo a nullptr
 */
Nodo::Nodo(const Cancion &cancion) : cancion(cancion), siguiente(nullptr) {}