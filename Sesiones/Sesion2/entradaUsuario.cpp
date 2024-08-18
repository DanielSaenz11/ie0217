/**
 * Programa que detalla la entrada y salida por terminal
 * cin: Input del usuario del teclado
 * cout: Mostrar en la terminal
 */

#include <iostream>
using namespace std;

int main() {
    // Declaracion de variable
    int x;

    cout << "Type a number: "; // Mostrar mensaje en pantalla
    cin >> x; // Recibir entrada del usuario
    cout << "Your number is: " << x; // Mostrar entrada previa

    return 0;
}