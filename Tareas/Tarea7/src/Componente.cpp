


#include "Componente.hpp"
#include <stdexcept>

Componente::Componente(const std::string& nombre,  int cantidad, const std::string& categoria, const std::string& descripcion)
    : nombre(nombre), cantidad(cantidad), categoria(categoria), descripcion(descripcion) {
    if (nombre == "") {
        throw std::invalid_argument("Error: El nombre no puede ser un string vacío.");
    }
    
    if (cantidad <= 0) {
        throw std::invalid_argument("Error: La cantidad debe ser mayor que cero.");
    }
}

void Componente::agregarComponente(int cantidad) {
    if (cantidad <= 0) {
        throw std::invalid_argument("Error: La cantidad debe ser mayor que cero.");
    }

    this->cantidad += cantidad;
}

bool Componente::reducirComponente(int cantidad) {
    if (cantidad <= 0) {
        throw std::invalid_argument("Error: La cantidad debe ser mayor que cero.");
    }
    
    if (this->cantidad < cantidad) return false;

    this->cantidad -= cantidad;
    return true;
}

const std::string Componente::getNombre() const {
    return nombre;
}

const std::string Componente::getCategoria() const {
    return categoria;
}

int Componente::getCantidad() const {
    return cantidad;
}

const std::string Componente::getDescripcion() const {
    return descripcion;
}
