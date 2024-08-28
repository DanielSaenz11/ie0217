/**
 * Codigo de la presentacion
 * Funcion amiga: Acceder a miembros fuera de la clase
 * 
 * Ejemplo de requirir funciones amigas
 * class MyClass {
 *     private:
 *         int member1;
 * }
 * 
 * int main() {
 *     MyClass obj;
 * 
 *     // Error! No se pueden procesar miembros aqui
 *     obj.member1 = 5;
 * }
 * 
 */

#include <iostream>
using namespace std;

// Declaracion de la clase Distance
class Distance {
    // Miembros privados
    private:
        int meter;

        // Funcion amiga
        friend int addFive(Distance);

    // Miembros publicos
    public:
        // Constructor de la clase (inicia meter en 0)
        Distance() : meter(0) {}
};

// Definicion de funcion amiga
int addFive(Distance d) {
    // Acceso de miembros privados por parte de la funcion amiga
    d.meter += 5;

    // Retorna valor de miembro privado
    return d.meter;
}

int main() {
    // Declaracion de objeto Distance
    Distance D;

    // Imprimir llamado de la funcion amiga addFive()
    cout << "Distance: " << addFive(D);
    
    return 0;
}