/*
Archivo con la función main(): Punto de entrada de ejecución del programa

Crea un objeto Estudiante y muestra su información
*/

#include <iostream>
#include "estudiante.hpp" // Incluir header file con la declaración de la clase Estudiante

int main() {
    // Crear objeto de clase Estudiante
    Estudiante estudiante("Juan", 20);
    
    // Cambio en el video: Nombre Esteban
    // Estudiante estudiante("Esteban", 20);

    // Mostrar datos del estudiante
    estudiante.mostrarDatos();

    return 0;
}