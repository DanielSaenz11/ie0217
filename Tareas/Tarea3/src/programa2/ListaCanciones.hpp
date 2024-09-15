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
         * Inicializa un objeto de la clase ListaCanciones y el nodo inicial de la lista como nullptr.
         */
        ListaCanciones();

        /**
         * @brief Destructor de la clase ListaCanciones
         * 
         * Libera la memoria dinámica de las canciones que se almacenan, por medio de un recorrido de la lista.
         */
        ~ListaCanciones();

        /**
         * @brief Función miembro para insertar una canción en la lista enlazada
         * 
         * Solicita al usuario que indique el tipo de inserción que quiere hacer: al inicio, al final
         * o en una posición en específico. Además, valida las entradas dependiendo del tipo escogido.
         * Realiza el llamado de las funciones respectivas en cada caso. 
         * 
         * @param cancion Objeto Cancion que se desea agregar a la lista
         * @return void
         */
        void insertarCancion(const Cancion &cancion);

        /**
         * @brief Función para insertar un objeto Cancion al inicio de la lista enlazada
         * 
         * Se agrega el nuevo nodo antes del nodo cabeza previo. De forma que, se coloca como siguiente nodo
         * al nodo cabeza y luego, se cambia la dirección a la apunta cabeza al nuevo nodo.
         * 
         * @param cancion Objeto Cancion para insertar en la primera posición
         * @return void
         */
        void insertarInicio(const Cancion &cancion);

        /**
         * @brief Función para insertar un objeto Cancion al final de la lista enlazada
         * 
         * Se recorre la lista hasta llegar al último valor. Se coloca como siguiente nodo del último, el nodo
         * recién creado.
         * 
         * @param cancion Objeto Cancion para insertar en la última posición
         * @return void
         */
        void insertarFinal(const Cancion &cancion);

        /**
         * @brief Función para insertar un objeto Cancion en una posición específica de la lista enlazada.
         * 
         * Se recorre la lista hasta alcanzar la posición deseada, mientras se rastrea el nodo anterior. Al alcanzar la posición,
         * se ajustan los punteros al nodo siguiente de cada uno (anterior y actual) para que la lista siga funcionando correctamente.
         * 
         * @param cancion Objeto Cancion para insertar en la primera posición
         * @param posicion Entero que representa la posición a insertar (0 -> Inicio)
         * @return void
         */
        void insertarPosicion(const Cancion &cancion, int posicion);

        /**
         * @brief Función miembro para eliminar una canción de la lista
         * 
         * Se recorre la lista enlazada en busca del nodo con el valor de interés. Si se encuentra, se analiza el caso de si
         * corresponde al nodo head (no tiene nodo anterior) o si es un nodo en el resto de la lista, que se tiene que manejar 
         * el puntero siguiente del nodo anterior para ajustar la lista correctamente. 
         * Se recibe el nombre de la canción a eliminar, se busca para ver si existe y se elimina, de ser así.
         * 
         * @param nombre Nombre de la canción a eliminar
         * @return void
         */
        void eliminarCancion(const std::string &nombre);

        /**
         * @brief Función miembro para modificar los atributos de un elemento de la lista
         * 
         * Se busca la canción para determinar si existe. De ser así, se solicitan los datos nuevos de la canción
         * y se utilizan las funciones setter del objeto Cancion para modificar cada uno de sus atributos.
         * 
         * @param nombre Nombre de la canción a modificar
         * @return void
         */
        void modificarCancion(const std::string &nombre);

        /**
         * @brief Función miembro para imprimir todos los elementos de la lista
         * 
         * Se muestran las canciones de forma secuencial, según el orden en el que fueron agregadas, por medio de
         * un recorrido de la lista enlazada con un while loop.
         * 
         * @return void
         */
        void imprimirLista() const;

        /**
         * @brief Función miembro para buscar una canción en la lista, a partir de su nombre
         * 
         * Se recorre la lista enlazada para determinar si existe un nodo que contenga el nombre de la canción buscada.
         * De ser así, se retorna ese nodo.
         * 
         * @param nombre Nombre de la canción a buscar
         * @return Nodo donde se encuentra la canción
         */
        Nodo* buscarCancion(const std::string &nombre) const;

};

#endif // LISTACANCIONES_HPP