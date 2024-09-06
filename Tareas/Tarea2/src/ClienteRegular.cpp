/**
 * @file ClienteRegular.cpp
 * @brief Archivo que contiene la implementación de los métodos de la clase ClienteRegular.
 * 
 * @details En este source file se incluye la definición del constructor de la clase ClienteRegular
 * y una función miembro sobrescrita de la clase abstracta Cliente, para aplicar un descuento específico al precio total.
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

// Header file con la declaración de la clase ClienteRegular
#include "ClienteRegular.hpp"

using namespace std;

// Definición del constructor de ClienteRegular: Asigna los parámetros recibidos a las variables miembro de la clase
ClienteRegular::ClienteRegular(string &nombre) : Cliente(nombre) {}

double ClienteRegular::aplicarDescuento(double total) const {
    return total; // Retorna el mismo valor total pues no se aplica descuento a los clientes regulares
}