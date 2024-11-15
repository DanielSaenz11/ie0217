/**
 * @file Componente.cpp
 * @brief Implementación de la clase Componente.
 * @details Este archivo contiene las implementaciones de los métodos de la clase `Componente`,
 * que modela un elemento del inventario con nombre, cantidad, categoría y descripción.
 * Proporciona funcionalidades para agregar y reducir cantidades, y obtener detalles del componente.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 15/11/2024
 */


#include "Componente.hpp"
#include <stdexcept>

// Constructor de la clase Componente
Componente::Componente(const std::string& nombre,  int cantidad, const std::string& categoria, const std::string& descripcion)
    : nombre(nombre), cantidad(cantidad), categoria(categoria), descripcion(descripcion) {
    // Validar que el nombre no sea un string vacío
    if (nombre == "") {
        throw std::invalid_argument("Error: El nombre no puede ser un string vacío.");
    }
    
    // Validar que la cantidad inicial sea mayor que 0
    if (cantidad <= 0) {
        throw std::invalid_argument("Error: La cantidad debe ser mayor que cero.");
    }
}

// Método para agregar una cantidad al componente
void Componente::agregarComponente(int cantidad) {
    // Validar que la cantidad a agregar sea mayor que cero
    if (cantidad <= 0) {
        throw std::invalid_argument("Error: La cantidad debe ser mayor que cero.");
    }

    this->cantidad += cantidad; // Incrementar la cantidad del componente
}

// Método para reducir una cantidad del componente
bool Componente::reducirComponente(int cantidad) {
    // Validar que la cantidad a reducir sea mayor que 0
    if (cantidad <= 0) {
        throw std::invalid_argument("Error: La cantidad debe ser mayor que cero.");
    }
    
    if (this->cantidad < cantidad) return false; // Verificar que hay suficientes

    this->cantidad -= cantidad; // Reducir la cantidad del componente
    return true; // Retornar que sí se pudo realizar la reducción correctamente
}

// Método para obtener el nombre del componente
const std::string Componente::getNombre() const {
    return nombre;
}

// Método para obtener la categoría del componente
const std::string Componente::getCategoria() const {
    return categoria;
}

// Método para obtener la cantidad disponible del componente
int Componente::getCantidad() const {
    return cantidad;
}

// Método para obtener la descripción del componente
const std::string Componente::getDescripcion() const {
    return descripcion;
}
