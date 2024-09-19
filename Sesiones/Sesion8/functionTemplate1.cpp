
/*
Function template:
Plantilla para funciones genérica que permite trabajar con diferentes
tipos de datos


Boilerplate:
template <typename T>
T functionName(T parameter1, T parameter2, ...) {
    // code
}

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
    cout << result1 << endl;

    // Llamar función con parámetros double
    result2 = add<double>(2.2, 3.3); // Análogo a declarar una función con tipos de dato double
    cout << result2 << endl;

    return 0;
}