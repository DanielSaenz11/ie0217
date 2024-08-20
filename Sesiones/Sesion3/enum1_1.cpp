/**
 * Enum: Representar un conjunto finito (valores especificos)
 */

#include <iostream>
using namespace std;

// Declaracion de enum
enum seasons { spring = 34, summer = 4, autumn = 9, winter = 32 };

int main() {
    seasons s;

    // Asignacion de valor
    s = summer;

    // Imprimir el valor numerico guardado
    cout << "Summer = " << s << endl;

    return 0;
}
