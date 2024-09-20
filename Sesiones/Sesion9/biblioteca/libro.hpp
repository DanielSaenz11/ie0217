/*
Header file con la declaración de la clase Libro
*/

#ifndef LIBRO_HPP
#define LIBRO_HPP

#include <string>

// Declaración de clase Libro
class Libro {
    public:
        // Constructor de Libro
        Libro(const std::string& titulo, const std::string& autor);

        // Método para mostrar la información del objeto
        void mostrarInfo() const;

    private:
        std::string titulo; // Título del libro
        std::string autor; // Autor del libro
};

#endif // LIBRO_HPP