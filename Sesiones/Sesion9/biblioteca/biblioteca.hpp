/*
Header file con la declaración de la clase Biblioteca
Métodos:
- agregarLibro()
- mostrarCatalogo()
*/

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector> 
#include "libro.hpp" // Incluir header file con la declaración de clase Libro

// Declaración de clase Biblioteca
class Biblioteca {
    public:
        // Método para agregar libro al catálogo
        void agregarLibro(
            const std::string& titulo,
            const std::string& autor
        );

        // Método para mostrar el cátalogo de libros
        void mostrarCatalogo();

    private:
        // Vector que contiene objetos Libro
        std::vector<Libro> catalogo;
};

#endif // BIBLIOTECA_HPP