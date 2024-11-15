


#include "Inventario.hpp"
#include <iostream>
#include <algorithm>

// Función para agregar un componente al inventario o incrementar su cantidad si ya existe
void Inventario::agregarComponente(const std::string& nombre, int cantidad, const std::string& categoria, const std::string& descripcion) {
    if (cantidad <= 0) {
        throw std::invalid_argument("Error: La cantidad debe ser mayor que cero.");
    }

    // Iterador que recorre el vector de componentes y busca si hay coindencia por nombre por medio de una función lambda
    auto it = std::find_if(componentes.begin(), componentes.end(), [&](const Componente& comp) {
        return comp.getNombre() == nombre;
    });

    if (it != componentes.end()) {
        // Si el componente ya existe, aumenta la cantidad
        it->agregarComponente(cantidad);
    } else {
        // Si no existe, añade un nuevo componente
        componentes.emplace_back(nombre, cantidad, categoria, descripcion);
    }
}

// Reducir la cantidad de un componente específico
bool Inventario::reducirComponente(const std::string& nombre, int cantidad) {
    if (cantidad <= 0) {
        throw std::invalid_argument("Error: La cantidad debe ser mayor que cero.");
    }

    auto it = std::find_if(componentes.begin(), componentes.end(), [&](const Componente& comp) {
        return comp.getNombre() == nombre;
    });

    if (it != componentes.end()) {
        // Si el componente existe, intenta reducir la cantidad
        return it->reducirComponente(cantidad);
    } else {
        // Si no existe, no se puede reducir
        throw std::runtime_error("Error: Componente no encontrado en el inventario.");
    }
}

// Listar todos los componentes, organizados por categoría
void Inventario::listarComponentes() const {
    if (componentes.empty()) {
        throw std::runtime_error("Error: El inventario está vacío.");
    }

    std::cout << "=== Inventario de Componentes ===\n";
    for (const auto& comp : componentes) {
        std::cout << "Nombre: " << comp.getNombre() << std::endl
                  << "Categoría: " << comp.getCategoria() << std::endl
                  << "Cantidad: " << comp.getCantidad() << std::endl
                  << "Descripción: " << comp.getDescripcion() << std::endl
                  << std::endl;
    }
}

// Buscar un componente específico por nombre y mostrar sus detalles
const Componente& Inventario::buscarComponente(const std::string& nombre) const {

    auto it = std::find_if(componentes.begin(), componentes.end(), [&](const Componente& comp) {
        return comp.getNombre() == nombre;
    });

    if (it != componentes.end()) {
        std::cout << "=== Componente encontrado ===" << std::endl
                  << "Nombre: " << it->getNombre() << std::endl
                  << "Categoría: " << it->getCategoria() << std::endl
                  << "Cantidad: " << it->getCantidad() << std::endl
                  << "Descripción: " << it->getDescripcion() << std::endl;
        return *it; // Retorna el componente encontrado
    } else {
        throw std::runtime_error("Error: Componente no encontrado en el inventario.");
    }
}
