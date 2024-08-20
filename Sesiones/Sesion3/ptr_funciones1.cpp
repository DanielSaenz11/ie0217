/**
 * Paso de argumento por valor o por referencia (sin punteros)
 */

#include <iostream>
using namespace std;

// Se pasa el valor de la variable
void func1(int numVal) {
    // code
}

// Se pasa la direccion de la variable como parametro de la funcion
void func2(int &numRef) {
    // code
}

int main() {
    int num = 5;

    // Paso por valor
    func1(num);

    // Paso por referencia
    func2(num);

    return 0;
}