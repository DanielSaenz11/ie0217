/**
 * @file ProductoFisico.cpp
 * @brief Archivo que contiene la implementación de los métodos de la clase ProductoFisico.
 * 
 * @details En este source file se incluye la definición del constructor de la clase ProductoFisico
 * y una función miembro que retorna el valor del atributo privado peso.
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

// Header file con la declaración de la clase ProductoFisico
#include "ProductoFisico.hpp"

using namespace std;

// Definición del constructor de ProductoFisico: Asigna los parámetros recibidos a las variables miembro de la clase
ProductoFisico::ProductoFisico(const std::string &nombre, double precio, double peso) :
Producto(nombre, precio), peso(peso) {}

double ProductoFisico::getPeso() const {
    return peso;
}

void ProductoFisico::mostrarInformacion() const {
    cout << "- Producto digital: " << nombre << " (Precio: $" << precio << ", Peso: " << peso << "kg)" << endl;
}
