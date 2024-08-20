/**
 * Punteros dobles
 * Repaso: Funcionamiento de puntero simple
 */

#include <iostream>
using namespace std;

int main() {
    // Declaracion de variable y puntero
    int var = 2050;
    int* ptr_var;

    // Asignacion de direccion de var a ptr_var
    ptr_var = &var;

    cout << "var: " << var << ", ptr_var: " << ptr_var << endl;

    return 0;
}