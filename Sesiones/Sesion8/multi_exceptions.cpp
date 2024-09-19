/*
Ejemplo realizado en el video sobre el manejo de excepciones múltiples
*/

#include <iostream>
using namespace std;

int main() {
    // Declaración de numerador, denominador y arreglo de resultados
    double numerator, denominator, arr[4] = {0.0, 0.0, 0.0, 0.0};
    int index; // Índice del arreglo

    // Ingreso del índice del arreglo
    cout << "Enter array index: ";
    cin >> index;

    // try clause
    try {
        // Si el índice ingresado es mayor que el índice máximo del arreglo
        if (index >= 4)
            throw "Error: Array out of bounds!"; // Levanta el error

        // El siguiente código no se ejecuta si el arreglo está fuera de rango
        cout << "Enter numerator: ";
        cin >> numerator; // Ingreso del numerator

        cout << "Enter denominator: ";
        cin >> denominator; // Ingreso del denominator

        // Levanta excepción si el denominador es 0
        if (denominator == 0)
            throw 0; // Levanta el error

        // El siguiente código no se ejecuta si el denominador es 0
        arr[index] = numerator / denominator; // Se realiza la división
        cout << arr[index] << endl; // Se imprime el resultado guardado en el índice del arreglo
    }

    // Atrapar excepción "Array out of bounds" -> Se espera una cadena de caracteres
    catch (const char* msg) {
        cout << msg << endl; // Imprime el mensaje de la excepción
    }
    // Atrapar excepción "Divide by 0"
    catch (int num) {
        cout << "Error: Cannot divide by " << num << endl;
    }
    // Atrapar otro tipo de excepciones no contempladas
    catch (...) {
        cout << "Unexpected exception!" << endl;
    }

    return 0;
}