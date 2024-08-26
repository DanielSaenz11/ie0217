/**
 * Ejemplo realizado por el profesor
 * Propiedades basicas de una clase
 * 
 * Formatos de hacer el constructor
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

        /* Constructor de la clase */

        // Tipo 1: Parametros y asignacion en la misma linea separados por :
        // Molde(double largo_p, double ancho_p, double alto_p) : largo(largo_p), ancho(ancho_p), alto(alto_p) {}

        // Tipo 2: Parametros en una linea y luego la asignacion dentro de {}
        Molde(double largo_p, double ancho_p, double alto_p) {
            largo = largo_p;
            ancho = ancho_p;
            alto = alto_p;
        }
};

int main() {
    // Comparar la declaracion de atributos y variables regulares
    int variable_entera;
    
    // Declaracion de instancia de Molde
    Molde pared(10.0, 20.0, 35.0);

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