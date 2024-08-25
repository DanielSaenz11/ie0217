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
            
            // Asignar valores iniciales a los atributos
            largo = 15;
            ancho = 12;
            alto = 21;
        }      
};

int main() {
    // Comparar la declaracion de atributos y variables regulares
    int variable_entera;
    
    // Declaracion de instancia de Molde
    Molde pared;

    // Imprimir el valor de pared.largo
    cout << pared.largo << endl;

    // Cambio de valor de pared.largo
    pared.largo = 20.0;

    // Imprimir nuevamente el valor de pared.largo
    cout << pared.largo << endl;

    // Cambio del resto de valores
    pared.ancho = 13.2;
    pared.alto = 23.4;

    return 0;
}