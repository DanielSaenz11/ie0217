/**
 * for Loop
 * 
 * for (init; condition; update) {
 *     if (condition to break) {
 *         break
 *     }
 * 
 *     if (condition to continue) {
 *         continue
 *     }
 * }
 * 
 * Se ejecuta hasta que la condicion se deje de cumplir
 */

#include <iostream>
using namespace std;

int main() {
    // Inicia en 1, incrementa en 1 y se detiene cuando es mayor que 5
    for (int i=1; i <= 5; ++i) {
        // 1 2 3 4 5
        cout << i << " ";
    }

    return 0;
}