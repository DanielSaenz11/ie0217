#include <iostream>

// Incluir header file
#include "funciones.hpp"

using namespace std;

void calculateAverage(Student s1, Student s2) {
    // Calculo de promedio de ambas calificaciones
    double average = (s1.marks + s2.marks) / 2;

    // Imprimir resultado
    cout << "Average Marks = " << average << endl;
}