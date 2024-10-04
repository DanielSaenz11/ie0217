/**
 * @file Funciones.cpp
 * @brief Implementación de las funciones libres para gestionar proyectos y tareas.
 *
 * @details Este archivo contiene las implementaciones de las funciones declaradas en Funciones.hpp.
 * Las funciones permiten manipular el mapa de proyectos y realizar operaciones como agregar,
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

#include "Funciones.hpp"

// Función para agregar un nuevo proyecto a partir de su nombre al vector de proyectos
void agregar_proyecto(std::map<std::string, Proyecto>& proyectos, const std::string& nombre) {
    // Si existe un proyecto con el nombre del proyecto nuevo, se lanza una excepción
    if (proyectos.find(nombre) != proyectos.end()) {
        throw std::invalid_argument("El proyecto ingresado ya existe en los proyectos almacenados.");
    }

    proyectos.emplace(nombre, Proyecto(nombre)); // Agregar proyecto creado al mapa de proyectos
    std::cout << "Proyecto " << nombre << " se ha agregado correctamente." << std::endl;
}

// Función miembro para eliminar un proyecto a partir de su nombre
void eliminar_proyecto(std::map<std::string, Proyecto>& proyectos, const std::string& nombre) {
    auto iterator = proyectos.find(nombre); // Iterador para encontrar una entrada en el mapa con el nombre ingresado como parámetro

    // Si el iterador llegó al final, no se encontró un proyecto con ese nombre y se lanza una excepción
    if (iterator == proyectos.end()) {
        throw std::invalid_argument("El proyecto ingresado no existe dentro de los proyectos almacenados.");
    }

    // Se elimina la entrada con la que hizo match el iterador al recorrer el mapa
    proyectos.erase(iterator);

    std::cout << "Proyecto " << nombre << " se ha eliminado correctamente." << std::endl;
}

// Función para mostrar las tareas a partir de un criterio de ordenamiento
void mostrar_tareas_por_criterio(std::map<std::string, Proyecto>& proyectos, const std::string& nombre) {
    auto iterator = proyectos.find(nombre); // Iterador para buscar un proyecto con el nombre ingresado
    if (iterator != proyectos.end()) {
        Proyecto& proyecto = iterator->second; // Asignar proyecto encontrado como proyecto
        int criterio; // Criterio de ordenamiento

        // Input del criterio de ordenamiento de las tareas
        std::cout << "Ingrese el criterio de ordenamiento (1=costo, 2=tiempo, 3=prioridad): ";
        std::cin >> criterio;

        // Estructura condicional para validar las entradas de la variable criterio
        if (criterio == 1) {
            proyecto.ordenar_tareas_por_costo();
        }
        else if (criterio == 2) {
            proyecto.ordenar_tareas_por_tiempo();
        }
        else if (criterio == 3) {
            proyecto.ordenar_tareas_por_prioridad();
        }
        else {
            // Si no es ninguna de las opciones posibles, se lanza una excepción para indicar que el criterio no es válido
            throw std::invalid_argument("Criterio de ordenamiento inválido.");
        }
        proyecto.mostrarTareas(); // Después del ordenamiento, se muestran las tareas
    } 
    else {
        // Si se ingresó un proyecto que no existe, se muestra una excepción
        throw std::runtime_error("El proyecto no fue encontrado.");
    }
}