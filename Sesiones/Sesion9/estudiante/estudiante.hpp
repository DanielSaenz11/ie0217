/*
Header file con la declaración de la clase Estudiante
*/

#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include <string>

// Declaración de la clase Estudiante
class Estudiante {
    public:
        // Constructor de la clase: Recibe nombre y edad
        Estudiante(const std::string& nombre, int edad);

        // Función para mostrar los datos del estudiante
        void mostrarDatos();

    private:
        std::string nombre; // Nombre del estudiante
        int edad; // Edad del estudiante
        int edad2; // No está en uso
};

#endif // ESTUDIANTE_HPP