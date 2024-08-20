/**
 * Caso 1: No se pasan argumentos a la funcion con parametros predefinidos
 * Se ejecuta la funcion con los argumentos ingresados en el prototipo de la funcion
 */

#include <iostream>
using namespace std;

// Prototipo de la funcion
void temp(int = 10, float = 8.8);

int main() {
    temp();

    return 0;
}

void temp(int i, float f) {
    cout << "Entero: " << i << endl;
    cout << "Float: " << f << endl;
}