/**
 * Uso de sobrecarga de funciones para mostrar con diferente texto si se ingresa
 * un numero entero, un double o ambos
 */

#include <iostream>
using namespace std;

/**
 * @brief Muestra un numero entero y un numero double
 * @param var1 Numero entero
 * @param var2 Numero double
 */
void display(int var1, double var2) {
    cout << "Integer number: " << var1;
    cout << " and double number: " << var2 << endl;
}

/**
 * @brief Muestra un numero double
 * @param var Numero double
 */
void display(double var) {
    cout << "Double number: " << var << endl;
}

/**
 * @brief Muestra un numero entero
 * @param var Numero entero
 */
void display(int var) {
    cout << "Integer number: " << var << endl;
}

int main() {

    // Definicion de variable entera y double
    int a = 5;
    double b = 5.5;

    // Llamado de funcion con entero
    display(a);

    // Llamado de funcion con double
    display(b);
    
    // Llamado de funcion con entero y double
    display(a, b);

    return 0;
}