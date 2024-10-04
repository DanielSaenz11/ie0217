/**
 * @file Proyecto.hpp
 * @brief Declaración de la clase Proyecto que gestiona una lista de tareas.
 *
 * @details La clase Proyecto contiene una colección de tareas en un vector. Además,
 * proporciona métodos para gestionar y manipular estas tareas, como agregar, eliminar y ordenarlas
 * por costo, tiempo estimado para completarlas y prioridad.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 04/10/2024
 */

#ifndef PROYECTO_HPP
#define PROYECTO_HPP

#include "TareaBase.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

/**
 * @class Proyecto
 * @brief Clase que representa un proyecto, el cual contiene una lista de tareas.
 *
 * La clase Proyecto utiliza un vector de punteros inteligentes para almacenar las tareas,
 * permitiendo un manejo eficiente y seguro de los recursos.
 */
class Proyecto {
    private:
        /// @brief Nombre del proyecto
        std::string nombre;

        /// @brief Vector que contiene las tareas del tipo TareaBase (por medio de polimorfismo)
        std::vector<std::shared_ptr<TareaBase>> tareas;

    public:
        /**
         * @brief Constructor de la clase Proyecto.
         *
         * Inicializa un proyecto con el nombre dado y un vector vacío de tareas.
         *
         * @param nombre Nombre del proyecto.
         */
        Proyecto(const std::string& nombre);

        /**
         * @brief Agrega una tarea al proyecto.
         *
         * Añade una nueva tarea al vector de tareas del proyecto.
         *
         * @param tarea Puntero compartido a la tarea a agregar.
         * @return void
         */
        void agregar_tarea(const std::shared_ptr<TareaBase>& tarea);

        /**
         * @brief Elimina una tarea del proyecto por su nombre.
         *
         * Busca la tarea por nombre y la elimina de la lista si se encuentra.
         *
         * @param nombre Nombre de la tarea a eliminar.
         * @return void
         * 
         * @throws std::runtime_error si la tarea no fue encontrada.
         */
        void eliminar_tarea(const std::string& nombre);

        /**
         * @brief Ordena las tareas por costo de manera ascendente.
         *
         * Utiliza la función std::sort para ordenar el vector de tareas basado en el costo.
         * 
         * @return void
         */
        void ordenar_tareas_por_costo();

        /**
         * @brief Ordena las tareas por tiempo estimado de manera descendente.
         *
         * Ordena las tareas de mayor a menor tiempo estimado usando std::sort.
         * 
         * @return void
         */
        void ordenar_tareas_por_tiempo();

        /**
         * @brief Ordena las tareas por prioridad (1 - alta, 2 - media, 3 - baja).
         *
         * Ordena las tareas según su prioridad de menor a mayor (alta a baja).
         * 
         * @return void
         */
        void ordenar_tareas_por_prioridad();

        /**
         * @brief Calcula el costo total de todas las tareas del proyecto.
         * 
         * @return El costo total del proyecto.
         */
        double calcular_costo_total();

        /**
         * @brief Calcula el tiempo total estimado para completar todas las tareas de un proyecto.
         * 
         * @return El tiempo total estimado del proyecto.
         */
        double calcular_tiempo_total();

        /**
         * @brief Muestra la información de todas las tareas del proyecto.
         *
         * Recorre la lista de tareas y llama al método mostrarInformacion de cada una.
         * Se ejecuta a lo interno de la clase Proyecto.
         * 
         * @return void
         */
        void mostrarTareas() const;

        /**
         * @brief Muestra un resumen del proyecto
         * 
         * Imprime en la consola el nombre, total de tareas, costo total y
         * tiempo estimado total
         * 
         * @return void
         */
        void mostrar_resumen_proyecto();

};

#endif // PROYECTO_HPP