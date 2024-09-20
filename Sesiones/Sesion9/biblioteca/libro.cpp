/*
Archivo de código fuente para la implementación de las funciones de la clase Libro
- Constructor
- mostrarInfo()
*/

#include <iostream>
#include "libro.hpp" // Incluir header file con la declaración de la clase Libro

// Constructor de la clase Libro: Recibe título y autor
Libro::Libro(
    const std::string& titulo, const std::string& autor
) : titulo(titulo), autor(autor) {}

// Método para mostrar la información del libro en la terminal
void Libro::mostrarInfo() const {
    std::cout << "Titulo: " << titulo << ", Autor: " << autor << std::endl; 
}