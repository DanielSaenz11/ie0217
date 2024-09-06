/**
 * @file Producto.hpp
 * @brief Archivo que contiene la declaración de la clase Producto.
 * 
 * @details En este header file se declara los atributos y miembros de la clase abstracta Producto, que
 * que gestiona el nombre del producto y su precio.
 * Incluye métodos como el constructor, destructor, obtener el precio del Producto y su nombre.
 * 
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

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <iostream>

/**
 * @class Producto
 * @brief Clase abstracta para productos de la tienda.
 * 
 * Esta clase almacena el nombre del producto y su precio como variables miembro privadas.
 * Proporciona métodos para construir un objeto de la clase (constructor), destructor,
 * obtener el precio del objeto y el nombre del producto.
 */
class Producto {
    protected:

        /// @brief Nombre del producto.
        std::string nombre;

        /// @brief Precio del producto.
        double precio;

    public:
        /**
         * @brief Constructor de la clase Producto.
         * 
         * Inicializa un producto con el nombre y precio proporcionado
         * 
         * @param nombre Nombre del producto.
         * @param precio Precio del producto.
         */
        Producto(const std::string &nombre, double precio);

        /**
         * @brief Destructor virtual de la clase Producto.
         * 
         * Utiliza el destructor predeterminado para clases.
         */
        virtual ~Producto() = default;

        /**
         * @brief Obtiene el precio del objeto Producto.
         * 
         * @return El precio del producto en cuestión.
         */
        double getPrecio() const;

        /**
         * @brief Obtiene el nombre del objeto Producto.
         * 
         * @return El nombre del producto en cuestión.
         */
        std::string getNombre() const;

        /**
         * @brief Muestra en un string la información del producto.
         * 
         * Corresponde a un método virtual puro.
         */
        virtual void mostrarInformacion() const = 0;
};

#endif // PRODUCTO_HPP