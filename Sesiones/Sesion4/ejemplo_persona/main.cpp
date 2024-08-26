/**
 * Punto de entrada de ejecucion del proyecto
 * Archivo donde se encuentra la funcion main()
 */

#include <iostream>
#include "persona.hpp"

using namespace std;

int main() {

    // Declaracion del objeto Persona
    Persona p("Juan", 25);

    // Imprimir detalles de la persona
    cout << "Nombre: " << p.getNombre() << endl;
    cout << "Edad: " << p.getEdad() << endl;

    // Cambiar valor de edad
    p.setEdad(26);

    // Imprimir nueva edad
    cout << "Nueva edad: " << p.getEdad() << endl;

    return 0;
}