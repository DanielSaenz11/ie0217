/**
 * while Loop: Se ejecuta siempre que se cumpla la condicion inicial
 * 
 * while (condition) {
 *     if (condition to break) {
 *         break
 *     }
 * 
 *     if (condition to continue) {
 *         continue
 *     }
 * }
 */

#include <iostream>
using namespace std;

int main() {
    // Inicializar i en 1
    int i = 1;

    // while loop from 1 to 5
    while (i <= 5) {
        cout << i << " ";

        ++i; // Incrementar i
    }

    return 0;
}