/**
 * Argumentos de una funcion
 * - Valor
 * - Referencia
 * - Puntero
 * - Por defecto
 */

#include <iostream>
using namespace std;

/**
 * @brief Imprime un numero entero y un float
 * @param n1 Numero entero
 * @param n2 Numero punto flotante
 */
void displayNum(int n1, float n2) {
    cout << "The int number is " << n1 << endl; // Se agrego el salto de linea
    cout << "The double number is " << n2 << endl;
}

int main() {
    // Declaracion de las variables que se van a pasar como argumento
    int num1 = 5;
    double num2 = 5.5;

    // Llamada de la funcion
    displayNum(num1, num2);

    return 0;
}