/**
 * @file Inventario.cpp
 * @brief Implementación de la clase Inventario.
 * @details Este archivo contiene las implementaciones de los métodos de la clase `Inventario`, 
 * que gestiona un conjunto de componentes electrónicos. Los métodos permiten agregar, reducir, 
 * listar y buscar componentes en el inventario.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 15/11/2024
 */


#include "Inventario.hpp"
#include <iostream>
#include <algorithm>
#include <map>

// Función para agregar un componente al inventario o incrementar su cantidad si ya existe
void Inventario::agregarComponente(const std::string& nombre, int cantidad, const std::string& categoria, const std::string& descripcion) {
    // Validar que la cantidad sea positiva
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
    // Validar que la cantidad sea positiva
    if (cantidad <= 0) {
        throw std::invalid_argument("Error: La cantidad debe ser mayor que cero.");
    }

    // Iterador que recorre el vector de componentes y busca si hay coindencia por nombre por medio de una función lambda
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
    // Verificar que el vector de componentes no esté vacío
    if (componentes.empty()) {
        throw std::runtime_error("Error: El inventario está vacío.");
    }

    // Usar un map para agrupar los componentes por categorías
    std::map<std::string, std::vector<Componente>> componentesPorCategoria;

    // Llenar el map con los componentes organizados por categoría
    for (const auto& comp : componentes) {
        componentesPorCategoria[comp.getCategoria()].push_back(comp);
    }

    // Imprimir los componentes agrupados por categorías
    std::cout << "=== Inventario de Componentes por Categoría ===\n";
    for (const auto& [categoria, listaComponentes] : componentesPorCategoria) {
        std::cout << "Categoría: " << categoria << "\n";
        for (const auto& comp : listaComponentes) {
            std::cout << "  Nombre: " << comp.getNombre() << std::endl
                      << "  Cantidad: " << comp.getCantidad() << std::endl
                      << "  Descripción: " << comp.getDescripcion() << std::endl
                      << std::endl;
        }
    }
}

// Buscar un componente específico por nombre y mostrar sus detalles
const Componente& Inventario::buscarComponente(const std::string& nombre) const {
    // Iterador que recorre el vector de componentes y busca si hay coindencia por nombre por medio de una función lambda
    auto it = std::find_if(componentes.begin(), componentes.end(), [&](const Componente& comp) {
        return comp.getNombre() == nombre;
    });

    // Si se encontró un componente con el nombre indicado
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
