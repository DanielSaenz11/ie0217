/**
 * Memoria dinamica con arrays
 * Reservar memoria memoria, acceder a ella y liberarla para arreglos
 */

#include <iostream>
using namespace std;

int main() {
    // Declaracion de numero total de estudiantes
    int num;

    // Ingreso de numero total de estudiantes por el usuario
    cout << "Enter total number of students: ";
    cin >> num;

    // Declaracion de puntero a memoria dinamica
    float *ptr;

    // Reservar memoria para un arreglo de floats de tamaño num en puntero ptr
    ptr = new float[num];

    cout << "Enter GPA of students." << endl;

    // Ingreso de GPA para cada entrada del array formado por memoria dinamica
    for (int i=0; i < num; i++) {
        cout << "Student " << i+1 << ": ";

        // Notacion: *(ptr + i) para acceder a la entrada i
        cin >> *(ptr + i); // ptr apunta al primer elemento del array
    }

    cout << "\nDisplaying GPA of students." << endl;

    // Impresion de GPA de estudiantes
    for (int i=0; i < num; i++) {
        cout << "Student " << i+1 << ": " << *(ptr + i) << endl; 
    }

    // Liberar memoria de ptr (todo el arreglo)
    delete[] ptr;

    return 0;
}