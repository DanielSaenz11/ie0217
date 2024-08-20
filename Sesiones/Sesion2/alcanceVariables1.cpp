/**
 * El programa declara las variables locales (dentro de main) a, b, c
 * La variable c corresponde a la suma de a y b
 * Las variables locales no se pueden acceder afuera de su scope
 */

#include <iostream>
using namespace std;

int main() {

    // Declaracion de variables locales
    int a, b;
    int c;


    // Inicializacion de las variables
    a = 10;
    b = 20;
    c = a + b;

    // Impresion del valor de c
    cout << c;

    return 0;
}