/**
 * Se pueden utilizar los miembros del enum independientes al enum como tal
 * Es decir, el nombre del miembro representa su valor en el programa
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

enum enumcito {
    carro, 
    casa,
    arbol,
    patio
};

int main() {
    seasons s;

    s = winter;

    cout << "Summer = " << s << endl;
    
    // El valor de MI_PRIMER_DEFINE representa el valor colocado en el #define
    cout << "Define = " << MI_PRIMER_DEFINE << endl;

    // Se puede colocar el nombre de cada miembro del enum independientemente
    cout << "arbol = " << arbol << endl;

    return 0;
}