/*
Uso de stdexcept para manejar las excepciones
*/

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    // Declaración de las variables de la división
    int numerador, denominador, resultado;

    // Input de los valores requeridos para la división
    cout << "Ingrese el numerador: "; 
    cin >> numerador;

    cout << "Ingrese el denominador: ";
    cin >> denominador;

    // try clause
    try {
        // Si el denominador es 0, se lanza un error en tiempo de ejecución
        if (denominador == 0)
            throw runtime_error("Error: el denominador no puede ser cero.");
        
        // Si no se ejecutó la excepción, se ejecuta el siguiente código
        resultado = numerador / denominador; // División
        cout << "El resultado es: " << resultado << endl; // Imprimir el resultado
    }
    // Atrapar la excepción en runtime
    catch (const exception& e) {
        cerr << e.what() << endl; // Imprimir por medio de cerr el error
    }

    return 0;
}