/*
Mala práctica de programación:

No se contemplan las posibles excepciones que se pueden generar
por la división entre 0

La ejecución del programa puede terminar inesperadamente
*/

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {

    // Declaración de las variables de la división
    int numerador, denominador, resultado;

    // Input de los valores para realizar la división
    cout << "Ingrese el numerador: "; 
    cin >> numerador;

    cout << "Ingrese el denominador: ";

    // Se realiza la división sin verificar los valores ingresados
    resultado = numerador / denominador;
    cout << "El resultado es: " << resultado << endl;

    return 0;
}