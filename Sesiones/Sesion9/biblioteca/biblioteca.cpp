/*
Archivo de código fuente para la implementación de las funciones de la clase Biblioteca
- agregarLibro()
- mostrarCatalogo()
*/

#include <iostream>
#include "biblioteca.hpp" // Incluir header file con la declaración de la clase

// Función que agrega un libro al final del vector catalogo
void Biblioteca::agregarLibro(
    const std::string& titulo,
    const std::string& autor
) {
    // Agrega objeto Libro al final del vector con los argumentos titulo y autor ingresados
    catalogo.emplace_back(titulo, autor);
}

// Función que muestra la información de cada libro del catálogo
void Biblioteca::mostrarCatalogo() {
    // Recorrido del vector catalogo
    for (const auto& libro : catalogo) {
        libro.mostrarInfo(); // Método para mostrar los atributos privados de cada libro
    }
}