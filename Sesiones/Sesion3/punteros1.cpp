/**
 * Los punteros almacenan la direccion de memoria de una variable
 * Desreferenciar un puntero (contenido al que apunta el puntero): *pointVar
 */

#include <iostream>
using namespace std;

int main() {
    // Definir variable
    int var = 5;

    // Declarar puntero
    int* pointVar;

    // Almacenar la direccion de var en pointVar
    pointVar = &var;

    // Imprimir el contenido de var y su direccion
    cout << "var = " << var << endl;
    cout << "Address of var (&var) = " << &var << endl
         << endl;

    // Imprimir el contenido del puntero (memoria) y el valor al desreferenciarlo
    cout << "pointVar = " << pointVar << endl;
    cout << "Content of the address pointed to by pointVar (*pointVar) = " << *pointVar << endl;

    return 0;
}