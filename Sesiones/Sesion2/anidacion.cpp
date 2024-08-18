/**
 * Anidacion de sentencias en la toma de decisiones
 * Se evalua primero las sentencias externas y luego las internas
 * 
 * outer if - outer else
 * inner if - inner else
 */

#include <iostream>
using namespace std;

int main() {
    int num;

    // Input de la variable por el usuario
    cout << "Enter an integer: ";
    cin >> num;

    // outer if condition 
    if (num != 0) {
        // Ejecuta este codigo si se cumple que num != 0

        // inner if condition
        if (num > 0) {
            cout << "The number is positive." << endl;
        }
        // inner else condition
        else {
            cout << "The number is negative." << endl;
        }
    }
    // outer else condition
    else {
        cout << "The number is 0 and it is neither positive or negative." << endl;
    }
    
    // Siempre se ejecuta pues no esta dentro de un condicional
    cout << "This line is always printed." << endl;

    return 0;
}