/*
Ejemplo realizado en el video de Function Templates
 */

#include <iostream>
using namespace std;

// Declaración de function template
template <typename T> // Colocar template y typename T
T add(T num1, T num2) {

    // Función add recibe parámetros del tipo T y retorna también un dato T
    return (num1 + num2);
}

int main() {
    // Declaración de variables para almacenar valores de retorno
    int result1;
    double result2;

    // Llamar función con parámetros enteros
    result1 = add<int>(2,3); // Análogo a declarar una función con tipos de dato int
    cout << "2 + 3 = " << result1 << endl;

    // Llamar función con parámetros double
    result2 = add<double>(2.2, 3.3); // Análogo a declarar una función con tipos de dato double
    cout << "2.2 + 3.3 = " << result2 << endl;

    return 0;
}