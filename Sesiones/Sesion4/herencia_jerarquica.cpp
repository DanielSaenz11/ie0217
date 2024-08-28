/**
 * Codigo de la presentacion
 * Herencia jerarquica
 */

#include <iostream>
using namespace std;

// Declaracion de la clase Animal
class Animal {
    // Miembros publicos
    public:
        // Metodo que imprime un mensaje para el objeto animal
        void info() { cout << "I am an animal." << endl; }
};

// Declaracion de la clase Dog (derivada de Animal)
class Dog : public Animal {
    // Miembros publicos
    public:
        // Metodo que imprime informacion del objeto Dog
        void bark() { cout << "Im am a Dog. Woof woof." << endl; }
};

// Declaracion de la clase Cat (derivada de Animal)
class Cat : public Animal {
    // Miembros publicos
    public:
        // Metodo que imprime informacion del objeto Cat
        void meow() { cout << "I am a Cat. Meow." << endl; }
};

int main() {
    // Crear objeto de la clase Dog
    Dog dog1;
    cout << "Dog Class:" << endl;
    dog1.info(); // Metodo de la clase Animal
    dog1.bark();

    // Crear objeto de la clase Cat
    Cat cat1;
    cout << "\nCat Class:" << endl;
    cat1.info(); // Metodo de la clase Animal
    cat1.meow();

    return 0;

}