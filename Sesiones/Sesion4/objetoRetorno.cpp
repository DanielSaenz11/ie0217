/**
 * Codigo de la presentacion
 * Programa que demuestra la funcionalidad de retornar objetos de clases por funciones
 */

#include <iostream>
using namespace std;

// Declaracion de la clase Student
class Student {
    // Elementos publicos
    public:
        double marks1, marks2;
};

// Funcion que crea un objeto Student y lo retorna
Student createStudent() {
    
    // Declaracion de objeto student
    Student student;

    // Asignar valores a los atributos publicos
    student.marks1 = 96.5;
    student.marks2 = 75.0;

    // Imprimir los marks de student
    cout << "Marks 1 = " << student.marks1 << endl;
    cout << "Marks 2 = " << student.marks2 << endl;

    // Retornar objeto creado
    return student;
}

int main() {
    // Declarar variable student1
    Student student1;

    // Asignar el valor retornado de la funcion createStudent() a student1
    student1 = createStudent();

    return 0;
}