/**
 * Swap del valor de variables por medio de uso de direcciones (sin punteros)
 */

#include <iostream>
using namespace std;

// Definicion de la funcion swap(): Recibe direcciones
/**
 * @brief Intercambia el valor que guardan dos variables
 * @param n1 Primer numero
 * @param n2 Segundo numero
 */
void swap(int &n1, int &n2) {
    int temp;

    temp = n1;
    n1 = n2;
    n2 = temp;
}

int main() {

    // Inicializar las variables
    int a = 1, b = 2;

    // Imprimir el valor que guardan las variables antes del cambio
    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // Intercambio
    swap(a, b);


    // Imprimir el valor que guardan las variables despues del cambio
    cout << "\nAfter swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    return 0;
}