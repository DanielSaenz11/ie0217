/**
 * @file Funciones.hpp
 * @brief Declaraciones de funciones libres para gestionar proyectos y tareas.
 *
 * @details Este archivo contiene las declaraciones de las funciones libres utilizadas para agregar,
 * eliminar y mostrar proyectos y tareas, así como para calcular el costo y tiempo total
 * de los proyectos.
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

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Proyecto.hpp"
#include <map>
#include <string>
#include <stdexcept>


/**
 * @brief Agrega un nuevo proyecto al mapa de proyectos.
 *  
 * La función verifica si el proyecto ya existe en el mapa.
 * Si no existe, lo agrega con el nombre proporcionado.
 * 
 * @param proyectos Referencia al mapa de proyectos.
 * @param nombre Nombre del proyecto a agregar.
 * 
 * @throws std::runtime_error si el proyecto ya existe.
 */
void agregar_proyecto(std::map<std::string, Proyecto>& proyectos, const std::string& nombre);


/**
 * @brief Elimina un proyecto existente del mapa de proyectos.
 * 
 * La función busca el proyecto por nombre y lo elimina del mapa si se encuentra.
 * 
 * @param proyectos Referencia al mapa de proyectos.
 * @param nombre Nombre del proyecto a eliminar.
 * 
 * @throws std::runtime_error si el proyecto no fue encontrado.
 */
void eliminar_proyecto(std::map<std::string, Proyecto>& proyectos, const std::string& nombre);


/**
 * @brief Muestra todas las tareas de un proyecto ordenadas según el criterio especificado.
 * 
 * Ordena las tareas del proyecto según el criterio proporcionado (costo, tiempo o prioridad)
 * y luego muestra la información de cada tarea.
 * 
 * Se ejecuta a lo externo de la clase Proyecto.
 * 
 * @param proyectos Referencia al mapa de proyectos.
 * @param nombre Nombre del proyecto.
 * 
 * @throws std::invalid_argument si el criterio es inválido.
 * @throws std::runtime_error si el proyecto no fue encontrado.
 */
void mostrar_tareas_por_criterio(std::map<std::string, Proyecto>& proyectos, const std::string& nombre);

#endif // FUNCIONES_HPP