/*
Function Templates con múltiples parámetros
*/

#include <iostream>
using namespace std;

// Contiene typename T y typename U
template <typename T, typename U>
T multiply(T a, U b) {
    // Recibe distintos tipos
    return a * b; // Retorna el resultado de su producto
}

int main() {
    // Declaración de factores
    int a = 3;
    double b = 4.5;

    // Uso de function template para recibir tipos int y double
    int result = multiply<int, double>(a, b);

    // Imprimir el resultado
    cout << "3 * 4.5 = " << result << endl;

    return 0;
}
