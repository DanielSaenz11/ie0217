/**
 * @file NodoCanciones.hpp
 * @brief Archivo que contiene la declaración del struct Nodo para la implementación de la lista de canciones.
 * 
 * @details En este header file se declaran la estructura de Nodo para la lista enlazada de canciones, junto con el
 * constructor de cada Nodo.
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

#ifndef NODOCANCIONES_HPP
#define NODOCANCIONES_HPP

#include "Cancion.hpp" // Header file que contiene la implementación de clase Cancion

/**
 * @brief Estructura que representa un nodo en la lista enlazada.
 * 
 * Cada nodo contiene un objeto de la clase Cancion y un puntero al siguiente nodo en la lista.
 */
struct Nodo {
    /// @brief Objeto que almacena la información de una canción
    Cancion cancion;

    /// @brief Puntero al siguiente nodo de la lista
    Nodo *siguiente;

    /**
     * @brief Constructor que inicializa un nodo con una canción.
     * 
     * Inicializa el valor del puntero al siguiente nodo a nullptr y cancion a la canción recibida
     * como argumento
     * 
     * @param cancion Objeto Cancion que se almacena en el nodo.
     */
    Nodo(const Cancion &cancion);
};

#endif // NODOLISTA_HPP