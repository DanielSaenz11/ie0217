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
        // Metodo base
        void print() {
            cout << "Base Function" << endl;
        }
};

class Derived : public Base {
    // Miembros publicos
    public:
        // Metodo modificado en la clase Derived
        void print() {
            cout << "Derived Function" << endl;
        }
};

int main() {
    // Declaracion de objetos de la clase Derived
    Derived derived1, derived2;

    // Uso del metodo modificado en la clase Derived
    derived1.print();

    // Uso del metodo definido en la clase Base
    derived2.Base::print();

    return 0;
}