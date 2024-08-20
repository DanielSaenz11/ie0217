/**
 * Caso 2: Se pasa el primer argumento
 * Se ejecuta la funcion con el primer argumento ingresado en main y el segundo predefinido
 */

#include <iostream>
using namespace std;

// Prototipo de la funcion
void temp(int = 10, float = 8.8);

int main() {
    // Se pasa unicamente un argumento -> primer argumento
    temp(6);

    return 0;
}

void temp(int i, float f) {
    cout << "Entero: " << i << endl;
    cout << "Float: " << f << endl;
}