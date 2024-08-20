/**
 * #define corresponde a una directiva de preprocesador para sustituir un valor
 * similar a una variable, pero que no existe en tiempo de ejecucion
 */

#include <iostream>
using namespace std;

// Directiva de preprocesador
#define BOOK_ID_MAX 10

int main() {
    // El valor de BOOK_ID_MAX es preprocesado
    cout << "El valor de BOOK_ID_MAX es: " << BOOK_ID_MAX << endl;

    return 0;
}