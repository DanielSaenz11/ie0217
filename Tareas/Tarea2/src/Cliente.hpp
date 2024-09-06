/**
 * @file Cliente.hpp
 * @brief Archivo que contiene la declaración de la clase abstracta Cliente.
 * 
 * @details En este header file se declara los atributos y miembros de la clase abstracta Cliente, que
 * que gestiona el nombre del cliente y los productos en su carrito.
 * Incluye métodos como el constructor, destructor, agregar producto, calcular total de la compra,
 * aplicar descuento dependiendo del tipo de cliente.
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

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <vector> // Estructura vector para almacenar productos
#include "Producto.hpp" // Header file con la declaración de la clase Producto

/**
 * @class Cliente
 * @brief Representa a un cliente de la tienda.
 * 
 * La clase Cliente almacena el nombre del cliente y los productos que ha agregado a su carrito.
 * Proporciona métodos para construir objetos, destruirlos, agregar productos, calcular el total
 * a pagar de los productos del carrito. Asimismo, se incluye un método para retornar el carrito
 * compras.
 * La clase se comporta como una clase abstracta pues se creó el método virtual puro aplicarDescuento().
 */
class Cliente {
    protected:
        /// @brief Nombre del cliente de la tienda.
        std::string nombre;

        /**
         * @brief Carrito de compras del cliente.
         * 
         * Estructura vector que contiene punteros a productos para representar el carrito del 
         * cliente. 
         */ 
        std::vector<Producto*> carrito;

    public:
        /**
         * @brief Constructor de la clase Cliente.
         * 
         * Inicializa un cliente con un nombre ingresado como parámetro.
         * 
         * @param nombre Nombre del cliente de la tienda.
         */
        Cliente(const std::string &nombre);

        /**
         * @brief Destructor de la clase Cliente.
         */
        virtual ~Cliente();

        /**
         * @brief Obtiene el nombre del cliente.
         * 
         * @return El nombre del cliente en cuestión.
         */
        std::string getNombre() const;

        /**
         * @brief Obtiene el carrito del cliente.
         * 
         * Función miembro que retorna un vector de punteros del tipo Producto que corresponde al 
         * carrito de compras del cliente.
         * 
         * @return El carrito del cliente en cuestión.
         */
        const std::vector<Producto*>& getCarrito() const;

        /**
         * @brief Agrega un producto al carrito de compras del cliente.
         * 
         * @param producto Producto para agregar al carrito.
         */
        void agregarProducto(Producto *producto);

        /**
         * @brief Calcular el total a pagar basándose en el carrito de compras.
         * 
         * Método que calcula el precio total de los productos en el carrito de compras.
         * 
         * @return Precio total.
         */
        double calcularTotal() const;

        /**
         * @brief Aplica el descuento al precio total a pagar.
         * 
         * Método virtual puro que aplica el descuento al total a pagar dependiendo del tipo de cliente.
         * Implementación en las clases derivadas.
         * 
         * @param total Total a pagar.
         * 
         * @return Precio final con descuento aplicado.
         */
        virtual double aplicarDescuento(double total) const = 0;

};

#endif // CLIENTE_HPP