/**
 * Punteros dobles
 * Imprimir el valor de un puntero doble y la direccion del puntero simple
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

    // Declaracion de puntero doble
    int** ptr_ptr_var;

    // Asignacion de direccion de ptr_var a ptr_ptr_var
    ptr_ptr_var = &ptr_var;

    // Imprimir valor de doble puntero
    cout << "ptr_ptr_var: " << ptr_ptr_var << endl;

    // Imprimir direccion de ptr_var
    cout << "&ptr_var: " << &ptr_var << endl;

    return 0;
}