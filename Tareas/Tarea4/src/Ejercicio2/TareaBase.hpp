/**
 * @file TareaBase.hpp
 * @brief Declaración de la clase base abstracta TareaBase.
 *
 * @details La clase TareaBase sirve como interfaz para las diferentes tareas que se manejarán
 * en el sistema. Define los métodos virtuales puros que deben ser implementados
 * por las clases derivadas. Su propósito es para ser utilizada como clase dentro de un vector de tareas.
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

#ifndef TAREABASE_HPP
#define TAREABASE_HPP

#include <string>

/**
 * @class TareaBase
 * @brief Clase base abstracta que representa una tarea genérica.
 *
 * Proporciona una interfaz común para todas las tareas. Se emplea para el
 * uso con polimorfismo en colecciones.
 */
class TareaBase {
public:
    /// @brief Destructor virtual por defecto.
    virtual ~TareaBase() = default;

    /**
     * @brief Obtiene el nombre de la tarea.
     *
     * @return Nombre de la tarea.
     */
    virtual std::string getNombre() const = 0;

    /**
     * @brief Obtiene el costo de la tarea.
     *
     * @return Costo de la tarea.
     */
    virtual double getCosto() const = 0;

    /**
     * @brief Obtiene el tiempo estimado para completar la tarea.
     *
     * @return Tiempo estimado de la tarea.
     */
    virtual double getTiempoEstimado() const = 0;

    /**
     * @brief Obtiene la prioridad de la tarea.
     *
     * @return Prioridad de la tarea.
     */
    virtual int getPrioridad() const = 0;

    /**
     * @brief Muestra la información de la tarea.
     *
     * @return void
     */
    virtual void mostrarTarea() const = 0;
};

#endif // TAREABASE_HPP
