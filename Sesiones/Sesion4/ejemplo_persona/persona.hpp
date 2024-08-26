/**
 * Header file
 * Declaracion de la clase
 */

#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <string>

using namespace std;

// Declaracion de la clase Persona
class Persona {
    // Elementos privados
    private:
        string nombre;
        int edad;

    // Elementos publicos
    public:
        // Constructor de la clase
        Persona(string nombre, int edad);
        
        // Metodo para retornar nombre
        string getNombre();
        
        // Metodo para retornar la edad
        int getEdad();

        // Metodo para cambiar el valor de la variable edad
        void setEdad(int edad);
};

#endif // PERSONA_HPP