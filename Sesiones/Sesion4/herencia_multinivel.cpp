/**
 * Codigo de la presentacion
 * Demostracion de herencia multinivel
 *
 * Clase Padre -> Clase Hijo -> Clase Nieto
 */

#include <iostream>
using namespace std;

// Declaracion de clase A
class A {
    // Elementos publicos
    public:
        // Metodo que muestra un mensaje de clase Padre
        void display() {
            cout << "Base class content.";
        }
};

// Declaracion de clase B (derivada de A)
class B : public A {};

// Declaracion de clase C (derivada de B)
class C : public B {};


int main() {
    // Declaracion de objeto de la clase C
    C obj;

    // Herencia multinivel: Se puede acceder al metodo de la clase A
    obj.display();

    return 0;
}