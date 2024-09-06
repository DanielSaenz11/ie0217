/**
 * @file Producto.cpp
 * @brief Archivo que contiene la implementación de los métodos de la clase Producto.
 * 
 * @details En este source file se definen los métodos de clase Producto correspondientes al constructor,
 * la función miembro que retorna el precio y el nombre del objeto.
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

// Header file con la declaración de la clase
#include "Producto.hpp"

using namespace std;

// Definición del constructor de Producto: Asigna los parámetros recibidos a las variables miembro de la clase
Producto::Producto(const std::string &nombre, double precio) : nombre(nombre), precio(precio) {}

double Producto::getPrecio() const {
    return precio;
}

string Producto::getNombre() const {
    return nombre;
}