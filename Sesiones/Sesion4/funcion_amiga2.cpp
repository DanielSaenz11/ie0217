/**
 * Codigo de la presentacion
 * Funcion amiga de dos clases diferentes
 */

#include <iostream>
using namespace std;

// Declaracion de clase ClassB
class ClassB;

// Declaracion de clase ClassA
class ClassA {
    // Miembros publicos
    public:
        // Constructor para inicializar numA a 12
        ClassA() : numA(12) {}

    private:
        int numA;

        // Declaracion de funcion amiga
        friend int add(ClassA, ClassB);
};

class ClassB {
    public:
        // Constructor para inicializar numB a 1
        ClassB() : numB(1) {}
    
    private:
        int numB;

        // Declaracion de funcion amiga
        friend int add(ClassA, ClassB);
};

// Acceso a miembros de ambas clases en la definicion de la funcion amiga
int add(ClassA objectA, ClassB objectB) {
    return (objectA.numA + objectB.numB);
}

int main() {
    // Declaracion de objetos de ClassA y ClassB
    ClassA objectA;
    ClassB objectB;

    // Imprimir suma de numA e numB
    cout << "Sum: " << add(objectA, objectB);

    return 0;

}