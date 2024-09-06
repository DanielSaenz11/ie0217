/**
 * @file ClienteRegular.hpp
 * @brief Archivo que contiene la declaración de la clase ClienteRegular.
 * 
 * @details En este header file se declara los atributos y miembros de la clase ClienteRegular.
 * Esta clase hereda los miembros de Cliente y sobrescribe el método virtual aplicarDescuento().
 * Además, incluye el método del constructor para instanciar objetos de esta clase.
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

#ifndef CLIENTE_REGULAR_HPP
#define CLIENTE_REGULAR_HPP

#include <iostream>

// Header file con la declaración de la clase Cliente
#include "Cliente.hpp"

/**
 * @class ClienteRegular
 * @brief Representa a los clientes regulares de la tienda.
 * 
 * La clase ClienteRegular hereda los miembros de la clase Cliente de forma pública.
 * Implementa la función miembro de aplicarDescuento() específica para la clase junto con el constructor.
 */
class ClienteRegular : public Cliente {
    public:
        /**
         * @brief Constructor de la clase ClienteRegular.
         * 
         * Inicializa un objeto cliente regular con el nombre ingresado como parámetro.
         * 
         * @param nombre Nombre del cliente regular.
         */
        ClienteRegular(std::string &nombre);

        /**
         * @brief Aplica el descuento al precio total a pagar.
         * 
         * Implementación del método sobrescrito que aplica el descuento al total a pagar para clientes regulares.
         * No se tiene un descuento para los clientes regulares, entonces retorna el total ingresado.
         * 
         * @param total Total a pagar.
         * 
         * @return Precio final con descuento aplicado.
         */
        double aplicarDescuento(double total) const override;
};

#endif // CLIENTE_REGULAR_HPP