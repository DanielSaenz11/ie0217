/*
Ejemplo realizado en el video donde se impide la división por 5
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
        if (denominator == 5)
            throw 5; // Levantamiento de excepción

        // Si no se ejecutó la excepción, se ejecuta la división
        divide = numerator / denominator; // Si se divide por 0, da inf

        // Imprimir el resultado de la división
        cout << numerator << " / " << denominator << " = " << divide << endl;
    }
    // Atrapar el error: valor de 0 en este caso
    catch (int num_exception) {
        cout << "Error: Cannot divide by " << num_exception << endl;
    }

    return 0;
}