/**
 * Se declara a g como una variable global (fuera de main)
 * No es necesario declarar a g dentro de main pues existe fuera de esta
 */

#include <iostream>
using namespace std;

// Declaracion de variable global
int g;

int main() {
    // Variables locales
    int a, b;

    // Inicializacion de variables locales
    a = 10;
    b = 20;

    // Global en terminos de locales
    g = a + b;

    // Se imprime g en la terminal
    cout << g;

    return 0;
}