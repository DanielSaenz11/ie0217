/*
Source file con la implementación de las funciones miembro de la clase Estudiante
*/

#include <iostream>
#include "estudiante.hpp" // Incluir header file con la declaración de clase Estudiante

// Constructor de la clase Estudiante: Recibe nombre y edad
Estudiante::Estudiante (
    const std::string& nombre, int edad
) : nombre(nombre), edad(edad) {}

// Función miembro para imprimir en la terminal el nombre y la edad del estudiante
void Estudiante::mostrarDatos() {
    std::cout << "Nombre: " << nombre;
    std::cout << ", Edad: " << edad << std::endl;

    // Cambio en el video: String en inglés
    // std::cout << "Name: " << nombre;
    // std::cout << ", Age: " << edad << std::endl;
}