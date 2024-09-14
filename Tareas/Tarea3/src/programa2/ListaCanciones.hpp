/**
 * @file ListaCanciones.hpp
 * @brief Archivo que contiene la declaración de la clase ListaCanciones.
 * 
 * @details En este header file se declara los atributos y miembros de la clase ListaCanciones, la cual corresponde
 * a la implementación de una lista enlazada. 
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

#ifndef LISTACANCIONES_HPP
#define LISTACANCIONES_HPP

#include <string> // std::string
#include "NodoCanciones.hpp" // Declaración de struct Nodo

/**
 * @class ListaCanciones
 * @brief Lista enlazada que contiene a objetos Cancion.
 * 
 * La clase ListaCanciones contiene el nodo inicial de la lista enlazada e implementa funciones para
 * operar sobre la lista enlazada: agregar elementos al inicio, final y en una posición específica, 
 * eliminar canciones, modificar canciones, imprimir la lista de canciones en la terminal y buscar
 * una canción por su nombre.
 */
class ListaCanciones {

    private:
        /// @brief Representa el inicio de la lista enlazada
        Nodo *cabeza;

    public:
        /**
         * @brief Constructor de la clase ListaCanciones
         * 
         * Inicializa un objeto de la clase ListaCanciones y el nodo inicial de la lista.
         */
        ListaCanciones();

        /**
         * @brief Destructor de la clase ListaCanciones
         * 
         * Libera la memoria dinámica de las canciones que se almacenan.
         */
        ~ListaCanciones();

        /**
         * @brief Función para insertar un objeto Cancion al inicio de la lista enlazada
         * 
         * @param cancion Objeto Cancion para insertar en la primera posición
         * @return void
         */
        void insertarInicio(const Cancion& cancion);

        /**
         * @brief Función para insertar un objeto Cancion al final de la lista enlazada
         * 
         * @param cancion Objeto Cancion para insertar en la última posición
         * @return void
         */
        void insertarFinal(const Cancion& cancion);

        /**
         * @brief Función para insertar un objeto Cancion en una posición específica de la lista enlazada.
         * 
         * @param cancion Objeto Cancion para insertar en la primera posición
         * @param posicion Entero que representa la posición a insertar (0 -> Inicio)
         * @return void
         */
        void insertarPosicion(const Cancion& cancion, int posicion);

        /**
         * @brief Función miembro para eliminar una canción de la lista
         * 
         * Se recibe el nombre de la canción a eliminar, se busca para ver si existe y se elimina, de ser así.
         * 
         * @param nombre Nombre de la canción a eliminar
         * @return void
         */
        void eliminarCancion(const std::string &nombre);

        /**
         * @brief Función miembro para modificar los atributos de un elemento de la lista
         * 
         * @param nombre Nombre de la canción a modificar
         * @return void
         */
        void modificarCancion(const std::string &nombre);

        /**
         * @brief Función miembro para imprimir todos los elementos de la lista
         * 
         * Se muestran las canciones de forma secuencial, según el orden en el que fueron agregadas.
         * 
         * @return void
         */
        void imprimirLista() const;

        /**
         * @brief Función miembro para buscar una canción en la lista, a partir de su nombre
         * 
         * @param nombre Nombre de la canción a buscar
         * @return Nodo donde se encuentra la canción
         */
        Nodo* buscarCancion(const std::string &nombre) const;

};

#endif // LISTACANCIONES_HPP