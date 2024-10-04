/**
 * @file Tarea.hpp
 * @brief Declaración de la class template Tarea para manejar diferentes tipos de recursos.
 *
 * @details La clase Tarea permite crear tareas con recursos de distintos tipos.
 * Hereda de TareaBase y proporciona implementaciones específicas para los métodos virtuales.
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


#ifndef TAREA_HPP
#define TAREA_HPP

#include "TareaBase.hpp" // Clase abstracta TareaBase
#include <iostream>
#include <string>

/**
 * @class Tarea
 * @brief Clase templada que representa una tarea con recursos de tipo genérico.
 *
 * Permite manejar tareas que requieren diferentes tipos de recursos.
 * Hereda los métodos de TareaBase, que fue creada para utilizar polimorfismo en estructuras de datos.
 *
 * @tparam T Tipo del recurso específico de la tarea.
 */
template <typename T>
class Tarea : public TareaBase {
    private:
        /// @brief Nombre de la tarea.
        std::string nombre;

        /// @brief Costo estimado de la tarea.
        double costo;

        /// @brief Tiempo estimado para completar la tarea.
        double tiempo_estimado;

        /// @brief Prioridad de la tarea (1-alta, 2-media, 3-baja).
        int prioridad;

        /// @brief Recursos específicos de la tarea
        T recursos;

    public:
        /**
         * @brief Constructor de la clase Tarea.
         *
         * Inicializa los atributos de la tarea y realiza la validación de los parámetros.
         *
         * @param nombre Nombre de la tarea.
         * @param costo Costo estimado de la tarea.
         * @param tiempo_estimado Tiempo estimado para completar la tarea.
         * @param prioridad Prioridad de la tarea (1-alta, 2-media, 3-baja).
         * @param recursos Recursos específicos de la tarea.
         * 
         * @throws std::invalid_argument si los parámetros son inválidos.
         */
        Tarea(const std::string& nombre, double costo, double tiempo_estimado, int prioridad, const T& recursos)
        : nombre(nombre), costo(costo), tiempo_estimado(tiempo_estimado), prioridad(prioridad), recursos(recursos) {
            // Validación de los argumentos
            if (costo < 0) throw std::invalid_argument("El costo debe ser un número positivo.");
            if (tiempo_estimado <= 0) throw std::invalid_argument("El tiempo estimado debe ser mayor que cero.");
            if (prioridad < 1 || prioridad > 3) throw std::invalid_argument("Prioridad no válida. Debe estar entre 1 (más alto) y 3 (más bajo).");
        }

        /**
         * @brief Obtiene el nombre de la tarea.
         *
         * @return Nombre de la tarea.
         */
        std::string getNombre() const override {
            return nombre;
        }

        /**
         * @brief Obtiene el costo de la tarea.
         *
         * @return Costo de la tarea.
         */
        double getCosto() const override {
            return costo;
        }

        /**
         * @brief Obtiene el tiempo estimado para completar la tarea.
         *
         * @return Tiempo estimado de la tarea.
         */
        double getTiempoEstimado() const override {
            return tiempo_estimado;
        }

        /**
         * @brief Obtiene la prioridad de la tarea.
         *
         * @return Prioridad de la tarea.
         */
        int getPrioridad() const override {
            return prioridad;
        }

        /**
         * @brief Obtiene los recursos específicos de la tarea.
         *
         * @return Recursos de la tarea.
         */
        T getRecursos() const {
            return recursos;
        }

        /**
         * @brief Asigna un nuevo nombre para la tarea.
         *
         * @param nuevoNombre Nuevo nombre de la tarea.
         * @return void
         */
        void setNombre(const std::string& nuevoNombre) {
            nombre = nuevoNombre;
        }

        /**
         * @brief Establece un nuevo costo para la tarea.
         *
         * Valida y actualiza el costo de la tarea.
         *
         * @param nuevoCosto Nuevo costo de la tarea.
         * @return void
         * 
         * @throws std::invalid_argument si el costo es negativo.
         */
        void setCosto(double nuevoCosto) {
            // Validación de nuevo costo ingresado
            if (nuevoCosto < 0) throw std::invalid_argument("El costo debe ser un número positivo.");
            
            costo = nuevoCosto;
        }

        /**
         * @brief Establece un nuevo tiempo estimado para la tarea.
         *
         * Valida y actualiza el tiempo estimado de la tarea.
         *
         * @param nuevo_tiempo_estimado Nuevo tiempo estimado.
         * @return void
         * 
         * @throws std::invalid_argument si el tiempo no es mayor que cero.
         */
        void setTiempoEstimado(double nuevo_tiempo_estimado) {
            // Validación de nuevo tiempo estimado ingresado
            if (nuevo_tiempo_estimado <= 0) throw std::invalid_argument("El tiempo estimado debe ser mayor que cero.");
            
            tiempo_estimado = nuevo_tiempo_estimado;
        }

        /**
         * @brief Establece una nueva prioridad para la tarea.
         *
         * Valida y actualiza la prioridad de la tarea.
         *
         * @param nuevaPrioridad Nueva prioridad (1-alta, 2-media, 3-baja).
         * @return void
         * 
         * @throws std::invalid_argument si la prioridad está fuera de rango.
         */
        void setPrioridad(int nuevaPrioridad) {
            // Validación de nueva prioridad ingresada
            if (nuevaPrioridad < 1 || nuevaPrioridad > 3) throw std::invalid_argument("Prioridad no válida. Debe estar entre 1 (más alto) y 3 (más bajo).");
            
            prioridad = nuevaPrioridad;
        }

        /**
         * @brief Establece nuevos recursos para la tarea.
         *
         * @param nuevosRecursos Nuevos recursos.
         * @return void
         */
        void setRecursos(const T& nuevosRecursos) {
            recursos = nuevosRecursos;
        }

        /**
         * @brief Muestra la información de la tarea.
         *
         * Imprime en la consola los detalles de la tarea con el formato:
         * 
         * Tarea: <nombre> (Costo: $<costo>, Tiempo estimado: <tiempo_estimado>, Prioridad: <prioridad>, Recursos: <recursos>)
         * 
         * @return void
         */
        void mostrarTarea() const override {
            // Imprimir el contenido de la tarea por medio de funciones miembro getters
            std::cout << "Tarea: " << getNombre() << " (Costo: $" << getCosto() << ", Tiempo Estimado: " << getTiempoEstimado() << ", Prioridad: "
            << getPrioridad() << ", Recursos: " << getRecursos() << ")" << std::endl;
        }
};


#endif // TAREA_HPP