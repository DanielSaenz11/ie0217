/**
 * Codigo de la presentacion
 * Clase amiga: Acceder a miembros privados de una clase desde otra clase
 */

#include <iostream>
using namespace std;

// Declaracion de ClassB
class ClassB;

// Declaracion de ClassA
class ClassA {
    // Miembros privados
    private:
        int numA;

        // Declaracion de la clase amiga
        friend class ClassB;

    // Miembros publicos
    public:
        // Constructor para inicializar numA a 12
        ClassA() : numA(12) {}
};

class ClassB {
    // Miembros privados
    private:
        int numB;

    // Miembros publicos
    public:
        // Constructor para inicializar numB a 1
        ClassB() : numB(1) {}

        // Member function
        // Se accede al atributo numA de la ClaseA
        int add() {
            // Declaracion de objeto de ClassA
            ClassA objectA;

            // Retornar la suma de numA (privado) y numB
            return objectA.numA + numB;
        }
};

int main() {
    // Declaracion de objeto de ClassB
    ClassB objectB;

    // Imprimir el llamado de la funcion miembro add()
    cout << "Sum: " << objectB.add();
    
    return 0;
}
