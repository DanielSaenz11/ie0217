/**
 * #define corresponde a una directiva de preprocesador para sustituir un valor
 * similar a una variable, pero que no existe en tiempo de ejecucion
 */

#include <iostream>
using namespace std;

#define BOOK_ID_MAX 10

enum {
    CASA_BADILLA,
    CASA_ALVARADO,
    CASA_SOLANO,
    CASA_MAX
} casas_t;

int main() {
    // El valor de BOOK_ID_MAX es preprocesado (se sustituye el 10 en su lugar)
    cout << "El valor de BOOK_ID_MAX es: " << BOOK_ID_MAX << endl;

    // Como se sigue un orden en el enum, CASA_MAX = 3
    cout << "La cantidad de casas en el condominio es: " << CASA_MAX << endl;

    return 0;
}