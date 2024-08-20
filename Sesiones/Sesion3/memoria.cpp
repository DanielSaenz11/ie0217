/**
 * Se utiliza & para acceder a la memoria de una variable
 * &var
 */

#include <iostream>
using namespace std;

int main() {
    // Declarar variables
    int var1 = 3;
    int var2 = 24;
    int var3 = 17;

    // Imprimir la direccion de var1
    cout << "Address of var1: " << &var1 << endl;

    // Imprimir la direccion de var2
    cout << "Address of var2: " << &var2 << endl;

    // Imprimir la direccion de var3
    cout << "Address of var3: " << &var3 << endl;

    return 0;
}