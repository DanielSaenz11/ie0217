/**
 * @file Cliente.cpp
 * @brief Archivo que contiene la implementación de los métodos de la clase abstracta Cliente.
 * 
 * @details En este source file se incluye la definición de los métodos para la clase Cliente correspondiente
 * al constructor, destructor, obtener el nombre del cliente y el carrito respectivo, agregar producto al
 * carrito de compras y calcular el precio total de los productos en el carrito.
 * Como la clase Cliente es abstracta, entonces no se implementa el método aplicarDescuento()
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

// Header file con la declaración de la clase Cliente
#include "Cliente.hpp"

using namespace std;

// Definición del constructor de Cliente: Asigna los parámetros recibidos a las variables miembro de la clase
Cliente::Cliente(const string &nombre) : nombre(nombre) {}

string Cliente::getNombre() const {
    return this->nombre;
}

const std::vector<Producto*>& Cliente::getCarrito() const {
    return carrito;
}

void Cliente::agregarProducto(Producto *producto) {
    carrito.push_back(producto); // Agregar producto al final del vector
}

double Cliente::calcularTotal() const {
    // Declaración de variable total
    double total = 0.0;

    // Recorrido por todos los productos en el carrito
    for (const Producto *producto : carrito) {
        total += producto->getPrecio(); // Añadir el total de cada uno
    }

    // Retornar precio total sumado
    return total;
}
