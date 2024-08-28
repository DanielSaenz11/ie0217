/**
 * Ejemplo realizado por el profesor
 * Propiedades basicas de una clase
 * 
 * Metodos de clases
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
        Molde(double largo_p, double ancho_p, double alto_p) : largo(largo_p), ancho(ancho_p), alto(alto_p) {
            cout << "Probando si se puede imprimir" << endl;
        }

        double calcularArea() {
            return largo * ancho;
        }

        double calcularVolumen() {
            return largo * ancho * alto;
        }

};

int main() {
    // Comparar la declaracion de atributos y variables regulares
    int variable_entera;
    
    // Declaracion de instancia de Molde
    Molde pared(10.0, 20.0, 35.0);

    // Imprimir el valor de pared.largo
    cout << "El area es: " << pared.calcularArea() << endl;
    cout << "El volumen es: " << pared.calcularVolumen() << endl;

    return 0;
}