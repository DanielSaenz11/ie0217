#include <iostream>
#include "sum.hpp"

using namespace std;

int main() {
    // Declaracion y definicion de sumandos
    int num1 = 5;
    int num2 = 3;

    // Llamado de la funcion
    int result = sum(num1, num2);

    // Imprimir resultado del programa
    cout << "El resultado de la suma de " << num1 << " y " << num2 << " es igual a: " << result << endl;

    return 0;
}

