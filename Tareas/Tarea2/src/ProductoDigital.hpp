/**
 * @file ProductoDigital.hpp
 * @brief Archivo que contiene la declaración de la clase ProductoDigital.
 * 
 * @details En este header file se declara los atributos y miembros de la clase ProductoDigital.
 * Esta hereda las variables y funciones miembro de la clase Producto. Añade el atributo de ID para
 * identificar los productos digitales.
 * Incluye métodos como el constructor y obtener el ID, aparte de los heredados.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 06/09/2024
 */

#ifndef PRODUCTO_DIGITAL_HPP
#define PRODUCTO_DIGITAL_HPP

// Header file con la declaración de la clase Producto
#include "Producto.hpp"

/**
 * @class ProductoDigital
 * @brief Representa a los productos digitales de la tienda.
 * 
 * La clase ProductoDigital hereda los atributos y métodos de la clase Producto de forma pública.
 * Contiene la declaración del constructor y el método para obtener el ID del producto.
 */
class ProductoDigital : public Producto {
    private:
        /// @brief ID del producto digital.
        std::string id;

    public:
        /**
         * @brief Constructor de la clase ProductoDigital.
         * 
         * Inicializa un producto digital con el nombre, precio e ID proporcionado.
         * 
         * @param nombre Nombre del producto digital.
         * @param precio Precio del producto digital.
         * @param id ID del producto digital.
         */
        ProductoDigital(const std::string &nombre, double precio, const std::string &id);

        /**
         * @brief Obtiene el ID del objeto ProductoDigital.
         * 
         * @return El ID del producto digital en cuestión.
         */
        std::string getId() const;
};

#endif // PRODUCTO_DIGITAL_HPP