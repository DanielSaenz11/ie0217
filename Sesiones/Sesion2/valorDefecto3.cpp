/**
 * Caso 3: Se pasan todos los argumentos
 * Se ejecuta la funcion con los dos argumentos ingresados en su llamado
 * 
 * Nota: Cuando se pasa unicamente el segundo, se genera un error pues se espera el primero
 *       debido a que la funcion se ejecuta por medio de argumentos posicionales
 * 
 * Ejemplo: 
 * 
 * temp(3.4) // Se espera un entero
 */

#include <iostream>
using namespace std;

// Prototipo de la funcion
void temp(int = 10, float = 8.8);

int main() {
    // Se pasan dos argumentos
    temp(6, -2.3);

    return 0;
}

void temp(int i, float f) {
    cout << "Entero: " << i << endl;
    cout << "Float: " << f << endl;
}