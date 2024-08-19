/**
 * Al declarar una variable estatica, tiene un tiempo de vida igual al tiempo
 * de ejecucion del programa
 * 
 * keyword: static [dataType] varName;
 */

#include <iostream>
using namespace std;

void test() {
    static int var = 0; // Definicion de la variable estatica
    ++ var;

    cout << var << endl;
}

int main() {
    // Primer llamado
    test(); // 1
    // Conserva su valor para el segundo llamado
    test(); // 2

    return 0;
}

