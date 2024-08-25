/**
 * Ejemplo realizado por el profesor
 * Propiedades basicas de una clase
 */

#include <iostream>
using namespace std;

// Declaracion de la clase Molde
class Molde {
    // Miembros publicos
    public:
        // Atributos
        double largo;
        double ancho;
        double alto;

        // Constructor de la clase
        Molde() {
            cout << "Instanciando Molde" << endl;
        }      
};

int main() {
    
    // Declaracion de instancia de Molde
    Molde pared;

    // Asignacion de valores a propiedades
    pared.largo = 20.0;
    pared.ancho = 13.2;
    pared.alto = 23.4;

    return 0;
}