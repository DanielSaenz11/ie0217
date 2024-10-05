/**
 * @file Proyecto.cpp
 * @brief Implementación de la clase Proyecto.
 *
 * @details Este archivo contiene las implementaciones de los métodos de la clase Proyecto,
 * incluyendo la gestión de tareas, las operaciones de ordenamiento y mostrar un resumen de ellas.
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


#include "Proyecto.hpp"
#include "Funciones.hpp"

using namespace std;

// Constructor recibe un string con el nombre del proyecto e inicializa el vector de tareas vacío
Proyecto::Proyecto(const std::string& nombre) : nombre(nombre) {}

// Función miembro para agregar una nueva tarea al vector
void Proyecto::agregar_tarea(const std::shared_ptr<TareaBase>& tarea) {
    tareas.push_back(tarea); // Agregar tarea al final del vector
}

// Función miembro para eliminar una tarea del vector a partir de su nombre
void Proyecto::eliminar_tarea(const std::string& nombre) {
    // Se utiliza la función del STL std::remove_if para recorrer el vector y eliminar la tarea si coincide con su nombre
    auto iterator = std::remove_if(tareas.begin(), tareas.end(),
        [&nombre](const std::shared_ptr<TareaBase>& tarea) {
            return tarea->getNombre() == nombre;
        });

    // Si se encontró la tarea, se elimina la tarea con la que se hizo match de nombre
    if (iterator != tareas.end()) {
        tareas.erase(iterator, tareas.end());
    } else {
        throw std::runtime_error("La tarea no fue encontrada."); // Error si no se encontró la tarea
    }
}

// Función miembro para ordenar las tareas dentro del vector por su costo
void Proyecto::ordenar_tareas_por_costo() {
    // Ordenar las tareas en el vector de forma ascendente a partir de su costo
    std::sort(tareas.begin(), tareas.end(),
        [](const std::shared_ptr<TareaBase>& a, const std::shared_ptr<TareaBase>& b) {
            return a->getCosto() < b->getCosto();
        });
}

// Función miembro para ordenar las tareas dentro del vector por su tiempo estimado
void Proyecto::ordenar_tareas_por_tiempo() {
    // Ordenar las tareas en el vector de forma descendente a partir de su tiempo estimado para ser completada
    std::sort(tareas.begin(), tareas.end(),
        [](const std::shared_ptr<TareaBase>& a, const std::shared_ptr<TareaBase>& b) {
            return a->getTiempoEstimado() > b->getTiempoEstimado();
        });
}

// Función miembro para ordenar las tareas dentro del vector por su prioridad
void Proyecto::ordenar_tareas_por_prioridad() {
    // Ordenar las tareas en el vector de forma ascendente a partir de su prioridad (primero se colocan los de prioridad 1)
    std::sort(tareas.begin(), tareas.end(),
        [](const std::shared_ptr<TareaBase>& a, const std::shared_ptr<TareaBase>& b) {
            return a->getPrioridad() < b->getPrioridad();
        });
}

// Función miembro para calcular el costo total de las tareas dentro del proyecto
double Proyecto::calcular_costo_total() {
    double costoTotal = 0; // Variable para almacenar la suma del costo de cada tarea

    // Recorrer las tareas almacenadas en el vector
    for (const auto& tarea : tareas) {
        costoTotal += tarea->getCosto(); // Obtener el costo de cada tarea
    }

    return costoTotal;
}

// Función miembro para calcular el tiempo total estimados de las tareas dentro del proyecto
double Proyecto::calcular_tiempo_total() {
    double tiempoTotal = 0; // Variable para almacenar la suma del tiempo estimado para cada tarea

    // Recorrer las tareas almacenadas en el vector
    for (const auto& tarea : tareas) {
        tiempoTotal += tarea->getTiempoEstimado(); // Obtener el tiempo estimado para cada tarea
    }

    return tiempoTotal;
}

// Función miembro que recorre y ejecuta el método para mostrar la información de las tareas
void Proyecto::mostrarTareas() const {
    // Recorrido del vector tareas
    for (const auto& tarea : tareas) {
        tarea->mostrarTarea();
    }
}

// Función miembro que muestra un resumen general del proyecto 
void Proyecto::mostrar_resumen_proyecto() {
    // Imprimir valores de la cantidad de tareas, el costo total y el tiempo total
    std::cout << "Proyecto: " << nombre << " (Total de tareas: " << tareas.size() << ", Costo total: " << calcular_costo_total()
    << ", Tiempo total: " << calcular_tiempo_total() << ")" << std::endl;
}