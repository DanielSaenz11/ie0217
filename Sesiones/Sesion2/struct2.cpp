/**
 * Programa que utiliza structs para guardar la informacion de una persona
 * Solicita la informacion, se almacena en el struct y luego la imprime
 * 
 */

#include <iostream>
using namespace std;

// Declaracion del struct
struct Person {
    char name[50];
    int age;
    float salary;
};

int main() {
    // Declaracion de struct Person
    Person p1;

    // Input de los datos del struct
    cout << "Enter Full name: ";
    cin.get(p1.name, 50);

    cout << "Enter age: ";
    cin >> p1.age;

    cout << "Enter salary: ";
    cin >> p1.salary;

    // Imprimir datos de p1
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p1.name << endl;
    cout << "Age: " << p1.age << endl;
    cout << "Salary: " << p1.salary << endl;

    return 0;
}