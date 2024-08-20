/**
 * Primero se deben colocar los parametros que no poseen un valor por defecto
 * Despues, se escriben los que si
 * 
 * Ejemplos invalidos:
 * 1) void add(int a, int b = 3, int c, int d);
 * 2) void add(int a, int b = 3, int c, int d = 4);
 * 
 * 3) Invalido porque no se coloca el prototipo de la funcion
 * int main() {
 *     // Llamada de la funcion
 *     display();
 * }
 * 
 * void display(char c = '*', int count = 5) {
 *     // code
 * }
 */

#include <iostream>
using namespace std;

// Ejemplo valido
void add(int, int, int = 3, int = 4);

int main() {
    // Se pasa unicamente un argumento -> primer argumento
    add(1, 2);

    return 0;
}

void add(int a, int c, int b, int d) {
    cout << "Suma total: " << a + b + c + d << endl;
}