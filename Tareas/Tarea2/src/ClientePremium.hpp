/**
 * @file ClientePremium.hpp
 * @brief Archivo que contiene la declaración de la clase ClientePremium.
 * 
 * @details En este header file se declara los atributos y miembros de la clase ClientePremium.
 * Esta clase hereda los miembros de la clase abstracta Cliente y añade el atributo privado de descuento.
 * Además, incluye métodos como el constructor y la implementación de la función virtual pura aplicarDescuento().
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

#ifndef CLIENTE_PREMIUM_HPP
#define CLIENTE_PREMIUM_HPP

#include <iostream>

// Header file que contiene la declaración de la clase Cliente
#include "Cliente.hpp"

/**
 * @class ClientePremium
 * @brief Representa un cliente del tipo premium en la tienda.
 * 
 * La clase ClientePremium hereda los miembros de la clase Cliente de forma pública.
 * Implementa un constructor y la función aplicarDescuento() sobrescrita.
 */
class ClientePremium : public Cliente {
    private:
        /// @brief Descuento específico para el cliente premium.
        double descuento;

    public:
        /**
         * @brief Constructor de la clase ClientePremium.
         * 
         * @param nombre Nombre del cliente premium.
         * @param descuento Descuento a aplicarle al cliente premium en las compras. Rango: [0-1[
         */
        ClientePremium(std::string &nombre, double descuento);

        /**
         * @brief Aplica el descuento al precio total a pagar.
         * 
         * Método sobrescrito de la clase abstracta Cliente que aplica el descuento al total a pagar
         * para el cliente premium.
         * 
         * @param total Total a pagar.
         * 
         * @return Precio final con descuento aplicado.
         */
        double aplicarDescuento(double total) const override;
};

#endif // CLIENTE_PREMIUM_HPP