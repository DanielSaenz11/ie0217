/**
 * @file ClientePremium.cpp
 * @brief Archivo que contiene la implementación de los métodos de la clase ClientePremium.
 * 
 * @details En este source file se incluye la definición del constructor de la clase ClientePremium
 * y una función miembro aplica el descuento al total a pagar para los productos del carrito.
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

// Header file con la declaración de la clase ClientePremium
#include "ClientePremium.hpp"

using namespace std;

// Definición del constructor de ClientePremium: Asigna los parámetros recibidos a las variables miembro de la clase
ClientePremium::ClientePremium(string &nombre, double descuento) : Cliente(nombre), descuento(descuento) {}

double ClientePremium::aplicarDescuento(double total) const {
    return ((1.0 - descuento) * total); // Cálculo del total a pagar con el descuento aplicado
}