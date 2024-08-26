/**
 * Codigo de la presentacion
 * Herencia multiple
 * Una clase deriva de dos o mas clases padre
 */

#include <iostream>
using namespace std;

// Declaracion de la clase Mammal
class Mammal {
    // Miembros publicos
    public:
        // Constructor de la clase
        Mammal() {
            cout << "Mammals can give direct birth" << endl;
        }
};

// Declaracion de la clase WingedAnimal
class WingedAnimal {
    // Miembros publicos
    public:
        // Constructor de la clase
        WingedAnimal() {
            cout << "Winged animal can flap." << endl;
        }
};

// Declaracion de la clase Bat (deriva de Mammal y WingedAnimal)
class Bat: public Mammal, public WingedAnimal {}; // Primero hereda de Mammal

int main() {
    // Declaracion de objeto Bat
    Bat b1; // Se ejecuta primero el mensaje de Mammal y luego de WingedAnimal
    return 0;
}