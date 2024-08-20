/**
 * Si un enum se inicia en un valor dado, los demas son consecutivos a ese valor
 * Como es el caso de enumcito mostrado a continuacion
 */

#include <iostream>
using namespace std;

// Directiva de preprocesador
#define MI_PRIMER_DEFINE 925

// Declaracion de enums
enum seasons {
    spring = 34,
    summer = 4,
    autumn = 9,
    winter = 32
};

// Inicia en 40
enum enumcito {
    carro = 40, 
    casa,
    arbol,
    patio
};

int main() {
    seasons s;

    s = winter;

    // Impresion de valor de enum y define
    cout << "Summer = " << s << endl;
    cout << "Define = " << MI_PRIMER_DEFINE << endl;

    // arbol contiene el valor de 42 pues se inicia en 40
    cout << "arbol = " << arbol << endl;

    return 0;
}