/**
 * @file Componente.hpp
 * @brief Declaración de la clase Componente para modelar un elemento en el inventario.
 * @details Este archivo contiene la definición de la clase `Componente`, que representa
 * un elemento del inventario con atributos como nombre, cantidad, categoría y descripción.
 * Proporciona métodos para agregar y reducir cantidades, así como para obtener detalles del componente.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 15/11/2024
 */

#ifndef COMPONENTE_HPP
#define COMPONENTE_HPP

#include <string>

/**
 * @brief Representa un componente del inventario.
 * @details La clase `Componente` modela un elemento del inventario, con atributos para
 * almacenar su nombre, cantidad, categoría y descripción. También incluye métodos
 * para modificar la cantidad y consultar los demás atributos.
 */
class Componente {
    private:
        /// @brief Nombre del componente
        std::string nombre;

        /// @brief Cantidad disponible del componente
        int cantidad;

        /// @brief Categoría del componente (Resistencia, Capacitor, Inductor)
        std::string categoria;

        /// @brief Descripción breve del componente
        std::string descripcion;

    public:
        /**
         * @brief Constructor de la clase Componente.
         * @details Inicializa un nuevo componente con los valores proporcionados para nombre, cantidad, 
         * categoría y descripción.
         * 
         * @param nombre Nombre del componente.
         * @param cantidad Cantidad inicial del componente.
         * @param categoria Categoría del componente.
         * @param descripcion Descripción del componente.
         */
        Componente(const std::string& nombre, int cantidad, const std::string& categoria, const std::string& descripcion);

        /**
         * @brief Incrementa la cantidad del componente.
         * @details Agrega una cantidad especificada al componente. 
         * La cantidad debe ser mayor que cero.
         * 
         * @param cantidad Cantidad a agregar.
         * @return `void`
         * @throws `std::invalid_argument` Si la cantidad es menor o igual a cero.
         */
        void agregarComponente(int cantidad);

        /**
         * @brief Reduce la cantidad del componente.
         * @details Disminuye la cantidad del componente en el inventario si hay suficiente stock.
         * 
         * @param cantidad Cantidad a reducir.
         * @return `true` si la operación fue exitosa, `false` si no hay suficiente stock.
         * @throws `std::invalid_argument` Si la cantidad es menor o igual a cero.
         */
        bool reducirComponente(int cantidad);

        /**
         * @brief Obtiene el nombre del componente.
         * 
         * @return `std::string` Nombre del componente.
         */
        const std::string getNombre() const;

        /**
         * @brief Obtiene la categoría del componente.
         * 
         * @return `std::string` Categoría del componente.
         */
        const std::string getCategoria() const;

        /**
         * @brief Obtiene la cantidad disponible del componente.
         * 
         * @return `std::string` Cantidad disponible del componente.
         */
        int getCantidad() const;

        /**
         * @brief Obtiene la descripción del componente.
         * 
         * @return `std::string` Descripción del componente.
         */
        const std::string getDescripcion() const;
};

#endif // COMPONENTE_HPP
