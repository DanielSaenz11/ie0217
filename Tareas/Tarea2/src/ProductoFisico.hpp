/**
 * @file ProductoFisico.hpp
 * @brief Archivo que contiene la declaración de la clase ProductoFisico.
 * 
 * @details En este header file se declara los atributos y miembros de la clase ProductoFisico.
 * Esta clase hereda los miembros de Producto y añade el atributo privado de peso.
 * Además, incluye métodos como el constructor y la obtención del atributo privado peso.
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

#ifndef PRODUCTO_FISICO_HPP
#define PRODUCTO_FISICO_HPP

// Header file con la implementación de clase Producto
#include "Producto.hpp"

/**
 * @class ProductoFisico
 * @brief Representa a los productos físicos de la tienda.
 * 
 * La clase ProductoFisico hereda los miembros de la clase Producto de forma pública.
 * Implementa el peso de los productos y una función miembro que retorna su valor.
 */
class ProductoFisico : public Producto {
    private:
        /// @brief Peso del producto físico.
        double peso;

    public:
        /**
         * @brief Constructor de la clase ProductoFisico.
         * 
         * Inicializa un producto físico con el nombre, precio y peso ingresado.
         * 
         * @param nombre Nombre del producto físico.
         * @param precio Precio del producto físico.
         * @param peso Peso del producto físico.
         */
        ProductoFisico(const std::string &nombre, double precio, double peso);

        /**
         * @brief Obtiene el peso del objeto ProductoFisico.
         * 
         * @return El peso del producto físico en cuestión.
         */
        double getPeso() const;
};

#endif // PRODUCTO_FISICO_HPP