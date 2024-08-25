/**
 * Codigo de la presentacion
 * Herencia de una clase de base a una derivada
 */

#include <iostream>
using namespace std;

// Declaracion de clase Animal
class Animal {
    // Elementos publicos
    public:
        // Metodo que imprime un mensaje de comer
        void eat() {
            cout << "I can eat!" << endl;
        }

        // Metodo que imprime un mensaje de dormir
        void sleep() {
            cout << "I can sleep!" << endl;
        }
};

// Declaracion de clase Dog (derivada de clase Animal -> Hereda miembros)
class Dog : public Animal {
    public:
        // Metodo que imprime un mensaje de ladrar
        void bark() {
            cout << "I can bark! Woof woof!!" << endl;
        }
};


int main() {
    // Declaracion de objeto de clase Dog
    Dog dog1;

    // Llamada de miembros de la clase base
    dog1.eat();
    dog1.sleep();

    // Llamado de miembros de la clase derivada
    dog1.bark();

    return 0;
}