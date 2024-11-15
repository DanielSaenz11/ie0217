/**
 * @file Inventario.hpp
 * @brief Declaración de la clase Inventario para gestionar un conjunto de componentes.
 * @details Este archivo contiene la definición de la clase `Inventario`, que permite
 * gestionar un conjunto de componentes electrónicos, proporcionando funcionalidades
 * para agregar, reducir, listar y buscar componentes.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 15/11/2024
 */


#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "Componente.hpp"
#include <vector>
#include <string>

/**
 * @brief Representa el inventario de componentes electrónicos.
 * @details La clase `Inventario` modela un conjunto de componentes electrónicos. 
 * Proporciona métodos para agregar componentes al inventario, reducir cantidades, listar
 * todos los componentes, y buscar un componente específico.
 */
class Inventario {
    private:
        /// @brief Lista de componentes en el inventario
        std::vector<Componente> componentes;

    public:
        /**
         * @brief Agrega un componente al inventario o incrementa su cantidad si ya existe.
         * @details Si el componente ya existe en el inventario, aumenta su cantidad. 
         * De lo contrario, lo agrega como un nuevo componente.
         * 
         * @param nombre Nombre del componente.
         * @param cantidad Cantidad a agregar.
         * @param categoria Categoría del componente.
         * @param descripcion Descripción del componente.
         * @return `void`
         * @throws `std::invalid_argument` Si la cantidad es menor o igual a cero.
         */
        void agregarComponente(const std::string& nombre, int cantidad, const std::string& categoria, const std::string& descripcion);

        /**
         * @brief Reduce la cantidad de un componente en el inventario.
         * @details Disminuye la cantidad de un componente específico si hay suficiente stock.
         * 
         * @param nombre Nombre del componente.
         * @param cantidad Cantidad a reducir.
         * @return `true` si la operación fue exitosa, `false` si el componente no tiene suficiente stock.
         * @throws `std::invalid_argument` Si la cantidad es menor o igual a cero.
         */
        bool reducirComponente(const std::string& nombre, int cantidad);

        /**
         * @brief Lista todos los componentes en el inventario.
         * @details Muestra los detalles de cada componente en el inventario. Si el inventario está vacío,
         * lanza una excepción.
         * 
         * @return `void`
         * @throws `std::runtime_error` Si el inventario está vacío.
         */
        void listarComponentes() const;

        /**
         * @brief Busca un componente específico por su nombre.
         * @details Devuelve una referencia constante al componente buscado. Si no se encuentra, lanza una excepción.
         * 
         * @param nombre Nombre del componente a buscar.
         * @return `Componente&` Una referencia constante al componente encontrado.
         * @throws `std::runtime_error` Si el componente no se encuentra en el inventario.
         */
        const Componente& buscarComponente(const std::string& nombre) const;
};

#endif // INVENTARIO_HPP
