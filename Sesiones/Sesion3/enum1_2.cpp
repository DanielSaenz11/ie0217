#include <iostream>
using namespace std;

// Declaracion del enum
enum seasons { spring = 34, summer = 4, autumn = 9, winter = 32 };

int main() {
    seasons s;

    // Asignacion del valor
    s = winter;

    // Imprimir el valor numerico guardado
    cout << "Winter = " << s << endl;

    return 0;
}