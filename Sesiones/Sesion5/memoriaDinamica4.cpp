/**
 * Memoria dinamica y clases
 * Declaracion y liberacion de un objeto de una clase con memoria dinamica
 */

#include <iostream>
using namespace std;

// Declaracion de clase Student
class Student {
    // Miembros privados
    private:
        int age;

    // Miembros publicos
    public:
        // Constructor: Inicializa age en 12
        Student() : age(12) {}

        // Funcion getter de age (miembro privado)
        void getAge() {
            cout << "Age = " << age << endl;
        }
};

int main() {
    // Declarar por medio de memoria dinamica objeto de la clase Student
    Student *ptr = new Student();

    // Llamar funcion getAge()
    ptr->getAge();

    // Liberar memoria dinamica de ptr
    delete ptr;

    return 0;
}