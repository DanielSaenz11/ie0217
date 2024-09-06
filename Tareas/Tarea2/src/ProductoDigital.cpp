/**
 * @file ProductoDigital.cpp
 * @brief Archivo que contiene la implementación de los métodos de la clase ProductoDigital.
 * 
 * @details En este source file se define el constructor de la clase ProductoDigital y la función
 * miembro que retorna el ID del producto.
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

// Header file con la declaración de la clase ProductoDigital
#include "ProductoDigital.hpp"

using namespace std;

// Definición del constructor de ProductoDigital: Asigna los parámetros recibidos a las variables miembro de la clase
ProductoDigital::ProductoDigital(const std::string &nombre, double precio, const std::string &id) : 
Producto(nombre, precio), id(id) {}

string ProductoDigital::getId() const {
    return id;
}

void ProductoDigital::mostrarInformacion() const {
    cout << "- Producto digital: " << nombre << " (Precio: $" << precio << ", ID: " << id << ")" << endl;
}
