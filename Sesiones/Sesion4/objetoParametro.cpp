/**
 * Codigo de la presentacion
 * Programa que demuestra el paso de objetos como parametros a funciones
 */

#include <iostream>
using namespace std;

// Declaracion de clase Student
class Student {
    // Elementos publicos
    public:
        double marks;

        // Constructor de la clase (recibe argumento flotante)
        Student(double m) {
            marks = m;
        }
};

// Funcion para calcular el promedio de dos estudiantes
void calculateAverage(Student s1, Student s2) {

    // Calcular el promedio de las notas
    double average = (s1.marks + s2.marks) / 2;

    // Imprimir el resultado en la variable averages
    cout << "Average marks = " << average << endl;
}

int main() {

    // Inicializar dos instancias de las clases Student
    Student student1(88.0), student2(56.0);

    // Pasar ambos objetos como argumento a calculateAverage()
    calculateAverage(student1, student2);

    return 0;
}