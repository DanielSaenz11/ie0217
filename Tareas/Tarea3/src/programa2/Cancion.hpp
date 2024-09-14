/**
 * @file Cancion.hpp
 * @brief Archivo que contiene la declaración de la clase Cancion.
 * 
 * @details En este header file se declara los atributos y miembros de la clase Cancion, que corresponde
 * a cada elemento que se almacena en la lista enlazada.
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

#ifndef CANCION_HPP
#define CANCION_HPP

#include <string> // std::string

/**
 * @class Cancion
 * @brief Representa una canción de la lista.
 * 
 * La clase Cancion almacena su nombre, el nombre del artista que la compuso y el valor de la duración
 * en minutos.
 * Incluye métodos como el constructor y funciones getters y setters para cada uno de sus atributos.
 */
class Cancion {
    private:
        /// @brief Nombre de la canción
        std::string nombre;

        /// @brief Nombre del artista que publicó la canción
        std::string artista;

        /// @brief Duración en minutos de la canción
        double duracion;

    public:
        /**
         * @brief Constructor de la clase
         * 
         * Inicializa un objeto de la clase Cancion, a partir de los parámetros ingresados para cada atributo.
         * 
         * @param nombre String con el nombre de la canción
         * @param artista String con el nombre del artista
         * @param duracion Double que representa la duración en minutos
         */
        Cancion(const std::string &nombre, const std::string &artista, double duracion);

        /**
         * @brief Obtiene el nombre de la canción
         * 
         * Función miembro getter del atributo privado nombre.
         * 
         * @return El nombre de la canción
         */
        std::string getNombre() const;
        
        /**
         * @brief Obtiene el artista de la canción
         * 
         * Función miembro getter del atributo privado artista.
         * 
         * @return El nombre del artista
         */
        std::string getArtista() const;

        /**
         * @brief Obtiene la duración de la canción
         * 
         * Función miembro getter del atributo privado duracion.
         * 
         * @return La duración
         */
        double getDuracion() const;

        /**
         * @brief Cambiar el nombre de la canción
         * 
         * Función miembro setter del atributo privado nombre.
         * 
         * @param nombre Nombre de cambio
         * @return void
         */
        void setNombre(const std::string &nombre);

        /**
         * @brief Cambiar el artista de la canción
         * 
         * Función miembro setter del atributo privado artista.
         * 
         * @param artista Artista de cambio
         * @return void
         */
        void setArtista(const std::string &artista);

        /**
         * @brief Cambiar la duración de la canción
         * 
         * Función miembro setter del atributo privado duracion.
         * 
         * @param duracion Duración de cambio
         * @return void
         */
        void setDuracion(double duracion);
};

#endif // CANCION_HPP