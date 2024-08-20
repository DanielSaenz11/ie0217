/**
 * do-while loop: Ejecuta una vez el codigo, luego se ejecuta siempre que se cumpla la condicion
 * 
 * do {
 *     code
 * }
 * while (condition);
 */

#include <iostream>
using namespace std;

int main() {

    // Inicializar variable en 1
    int i = 1;

    do {
        cout << i << " ";
        ++i; // Incrementar i
    }
    while (i <= 5); // Condicion del loop

    return 0;
}