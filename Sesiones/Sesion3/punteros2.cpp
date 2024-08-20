/**
 * Errores comunes al usar punteros: 
 * int var;
 * int* pointVar;
 * 
 * 1) pointVar = var; // Uno es puntero y el otro entero
 * 2) *pointVar = &var; // *pointVar apunta al valor de la direccion, no la direccion
 * 
 * Uso correcto
 * 1) pointVar = &var; // Direccion con direccion
 * 2) *pointVar = var; // Valor con valor
 */

#include <iostream>
using namespace std;

int main() {

    // Definir variable en 5
    int var = 5;

    // Declaracion del puntero
    int* pointVar;

    // Almacenar direccion de la variable en el puntero
    pointVar = &var;

    // Imprimir var
    cout << "var = " << var << endl;

    // Imprimir *pointVar
    cout << "*pointVar = " << *pointVar << endl
         << endl;

    cout << "Changing the value of var to 7:" << endl;

    // Cambiar el valor de var a 7
    var = 7;

    // Imprimir var
    cout << "var = " << var << endl;

    // Imprimir pointVar
    cout << "*pointVar = " << *pointVar << endl
          << endl;

    cout << "Changing the value of *pointVar to 16:" << endl;

    // Cambiar el valor de *pointVar a 16
    *pointVar = 16;

    // Imprimir var
    cout << "var = " << var << endl;

    // Imprimir *pointVar
    cout << "*pointVar = " << *pointVar << endl;

    return 0;
}