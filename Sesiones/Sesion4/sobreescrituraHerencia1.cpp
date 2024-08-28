/**
 * Codigo de la presentacion
 * Sobreescritura de herencia en miembro derivado
 */

#include <iostream>
using namespace std;

// Declaracion de la clase Base
class Base {
    // Miembros publicos
    public:
        // Metodo de la clase Base
        void print() {
            cout << "Base Function" << endl;
        }
};

// Declaracion de la clase Derived
class Derived : public Base {
    // Miembros publicos
    public:
        // Metodo sobreescrito en la clase Derived
        void print() {
            cout << "Derived Function" << endl;
        }
};

int main() {
    // Declaracion de objeto derivado
    Derived derived1;

    // Uso de metodo print() -> Se ejecuta el modificado
    derived1.print();

    return 0;
}