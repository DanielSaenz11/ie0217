/**
 * Codigo de la presentacion
 * Uso de funciones virtuales:
 * Puntero de la clase Base apunta a objeto de la clase Derived
 * Se ejecutan los miembros de la Derived class 
 */

#include <iostream>
using namespace std;

// Declaracion de la clase Base
class Base {
    public:
        // Uso de virtual keyword
        virtual void print() {
            // code
            cout << "Hola" << endl;
        }
};

// Declaracion de clase Derived (derivada de Base)
class Derived : public Base {
    public:
        void print() {
            // code
            cout << "Adios" << endl;
        }
};

int main() {
    // Declaracion de objeto de clase Derived
    Derived derived1;

    // Puntero de clase Base apunta a objeto de la clase Derived
    Base* base1 = &derived1;

    // Llamada de funcion de Derived class
    base1->print();

    return 0;
}