/**
 * Aplicacion de la sobrecarga de funciones para una funcion que determina el
 * valor absoluto de un numero, ya sea entero o punto flotante
 */

#include <iostream>
using namespace std;

/**
 * @brief Calcula el valor absoluto de un numero punto flotante
 * @param var Numero punto flotante
 * @return Valor absoluto de var
 */
float absolute(float var) {
    if (var < 0.0) {
        var = -var;
    }
    return var;
}

/**
 * @brief Calcula el valor absoluto de un numero entero
 * @param var Numero entero
 * @return Valor absoluto de var
 */
int absolute(int var) {
    if (var < 0) {
        var = -var;
    }
    return var;
}

int main() {
    // Imprimir valor absoluto de -5
    cout << "Absolute value of -5 = " << absolute(-5) << endl;
    
    // Imprimir valor absoluto de 5.5
    cout << "Absolute value of 5.5 = " << absolute(5.5f) << endl;

    return 0;
}