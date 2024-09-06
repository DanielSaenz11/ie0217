/**
 * @file Tienda.hpp
 * @brief Archivo que contiene la declaración de la clase Tienda.
 * 
 * @details En este header file se declara los atributos y miembros de la clase Tienda.
 * Esta clase contiene un vector con los productos disponibles en la tienda y un vector con los clientes registrados.
 * Se declaran los métodos de destructor, agregar cliente, procesar compra, buscar un cliente dentro del vector almacenado
 * y buscar un producto.
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

#ifndef TIENDA_HPP
#define TIENDA_HPP

#include <vector> // Vector para almacenar los productos y clientes
#include "Producto.hpp" // Header file con la declaración de clase Producto
#include "Cliente.hpp" // Header file con la declaración de clase Cliente

/**
 * @class Tienda
 * @brief Representa una tienda que posee clientes y productos.
 * 
 * La clase Tienda contiene un vector con los productos disponibles en la tienda y un vector con los clientes 
 * registrados. Asimismo, posee los métodos del destructor, agregar cliente, procesar compra, buscar un cliente
 * y buscar un producto dentro de los vectores designados para almacenarlos.
 */
class Tienda {
    private:
        /**
         * @brief Productos disponibles en la tienda.
         * 
         * Corresponde a un vector con punteros de la clase Producto que almacena cada uno de los productos almacenados.
         */
        std::vector<Producto*> productosDisponibles;

        /**
         * @brief Clientes registrados en la tienda.
         * 
         * Corresponde a un vector con punteros de la clase Cliente
         */
        std::vector<Cliente*> clientes;

    public:
        /**
         * @brief Destructor de la clase Tienda.
         * 
         * Se encarga de liberar la memoria de los productos y clientes registrados.
         */
        ~Tienda();

        /**
         * @brief Agregar un producto a la tienda.
         * 
         * Método que agrega un nuevo producto al vector de productosDisponibles.
         * 
         * @param producto Puntero del tipo Producto.
         * @return void
         */
        void agregarProducto(Producto *producto);

        /**
         * @brief Agregar un nuevo cliente a la tienda.
         * 
         * @param cliente Puntero del tipo Cliente.
         * @return void
         */
        void agregarCliente(Cliente* cliente);

        /**
         * @brief Procesa la compra de un cliente.
         * 
         * Método que calcula el total a pagar por un cliente ingresado como parámetro.
         * Muestra la lista de productos y el precio correspondiente.
         * 
         * @param nombreCliente Nombre del cliente para procesar la compra.
         * @return void
         */
        void procesarCompra(const std::string &nombreCliente) const;

        /**
         * @brief Busca un cliente dentro del vector clientes.
         * 
         * @param nombreCliente Nombre del cliente para buscar.
         * @return Puntero al cliente si fue encontrado o nullptr
         */
        Cliente* buscarCliente(const std::string &nombreCliente) const;

        /**
         * @brief Busca un producto dentro del vector productosDisponibles.
         * 
         * @param nombreProducto Nombre del producto para buscar.
         * @return Puntero al producto si fue encontrado o nullptr
         */
        Producto* buscarProducto(const std::string &nombreProducto) const;
};

#endif // TIENDA_HPP