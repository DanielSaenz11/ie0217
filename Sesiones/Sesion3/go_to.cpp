/**
 * Sentencia goto
 * Sirve para saltar a cualquier parte del programa (no es tan recomendable)
 */

#include <iostream>
using namespace std;

int main() {
    // Declaracion de las variables
    float num, average, sum = 0.0;
    int i, n;

    // Input de cantidad de numeros a analizar
    cout << "Maximum numbers of inputs: ";
    cin >> n;

    for (i = 1; i<= n; ++i) {
        // Input de cada numero
        cout << "Enter n" << i << ": ";
        cin >> num;

        // Si es negativo, se va a al calculo del promedio directamente
        if (num < 0.0) {
            // Se dirige al label jump
            goto jump;
        }
        
        sum += num;
    }

    // Calculo del promedio
    jump:
        average = sum / (i-1);
        cout << "\nAverage = " << average;
        return 0;
}

