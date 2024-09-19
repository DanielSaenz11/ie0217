/*
Manejo de excepciones en C++

try {
    // Código que puede levantar una excepción
    throw argument;
}
catch (exception) {
    // Código para manejar una excepción
}
*/

#include <iostream>
using namespace std;

int main() {

    // Declarar variables de la fracción
    double numerator, denominator, divide;

    // Input del numerador
    cout << "Enter numerator: ";
    cin >> numerator;

    // Input del denominador
    cout << "Enter denominator: ";
    cin >> denominator;

    // Try clause
    try {
        // Lanza una excepcion si el denominador es 0
        if (denominator == 0)
            throw 0; // Levantamiento de excepción

        // Si no se ejecutó la excepción, se ejecuta la división
        divide = numerator / denominator;

        // Imprimir el resultado de la división
        cout << numerator << " / " << denominator << " = " << divide << endl;
    }
    // Atrapar el error: valor de 0 en este caso
    catch (int num_exception) {
        cout << "Error: Cannot divide by " << num_exception << endl;
    }

    return 0;
}