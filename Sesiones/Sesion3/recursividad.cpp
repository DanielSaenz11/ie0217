/**
 * Calculo del factorial de un numero
 * Por medio de llamadas recursivas de la funcion
 */

#include <iostream>
using namespace std;

/**
 * @brief Calcula el factorial de un numero
 * @param n Numero entero
 * @return Factorial de 'n'
 */
int factorial(int);

int main() {
    int n, result;

    cout << "Enter a non-negative number: ";
    cin >> n;

    result = factorial(n);

    cout << "Factorial of " << n << " = " << result << endl;

    return 0;
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    }
    // Caso base de la recursion
    else {
        return 1;
    }
}

