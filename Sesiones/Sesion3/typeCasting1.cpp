/**
 * Type Casting implicito
 * type2_var = type1_var;
 */

#include <iostream>
using namespace std;

int main() {
    // Declaracion y definicion de numero entero
    int num_int = 9;

    // Declaracion de variable tipo double
    double num_double;

    // Asignar valor de variable integer a double (implicito)
    num_double = num_int;

    // Imprimir variable original y casting
    cout << "num_int = " << num_int << endl;
    cout << "num_double = " << num_double << endl;

    return 0;
}