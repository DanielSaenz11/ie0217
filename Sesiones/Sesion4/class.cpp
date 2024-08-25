/**
 * Codigo de la presentacion:
 * Boilerplate de una clase: Conjunto de lineas que se repiten
 * 
 * class NombreClase {
 *     private:
 *         // Atributos privados de la clase
 *         tipo_dato atributo1;
 *         tipo_dato atributo2;
 *         // ...
 *     public:
 *         // Constructores
 *         NombreClase();
 *         NombreClase(tipo_dato parametro1, tipo_dato parametro2, ...);
 * 
 *         // Destructor
 *         ~NombreClase();
 * 
 * 
 *         // Metodos publicos de la clase
 *         tipo_dato metodo1(tipo_parametro parametro1, tipo_parametro parametro2, ...);
 *         tipo_dato metodo2(tipo_parametro parametro1, tipo_parametro parametro2, ...);
 *         // ...
 * };
 * 
 * Programa para calcular el area y volumen a partir de una clase Molde
 */

#include <iostream>
using namespace std;

class Molde {

    // Tipo de acceso: Elementos publicos
    public:
        double largo;
        double ancho;
        double altura;

    // Constructor de la clase (mismo nombre)
    Molde() {
        cout << "Esto se ejecuta en cada instanciacion" << endl;
        cout << "Iniciando un objeto de la clase Room" << endl;
    }

    // Metodo que calcula el area de una instancia basado en los atributos de molde
    double calcularArea() {
        return largo * ancho;
    }

    // Metodo que calcula el volumen de una instancia basado en los atributos de molde
    double calcularVolumen() {
        return largo * ancho * altura;
    }

};

int main() {
    /* Instanciar un objeto llamado pared basado en la clase Molde */
    Molde pared;

    /* Asignar valores al objeto pared (se pueden acceder porque estan publicos) */
    pared.largo = 400.5;
    pared.ancho = 20.8;
    pared.altura = 315.2;

    /* Calcular y desplegar el area y volumen */
    cout << "Area = " << pared.calcularArea() << endl;
    cout << "Volumen = " << pared.calcularVolumen() << endl;

    return 0;
}