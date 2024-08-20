/**
 * Type Casting explicito
 * type2_var = (type2)type1_var;
 * 
 * En el ejemplo, como se convierte de double a int, en la salida se pierden los decimales
 */

#include <iostream>
using namespace std;

int main() {
    // Inicializar variable double
    double num_double = 3.56;
    
    cout << "num_double = " << num_double << endl;

    // C-style conversion from double to int
    int num_int1 = (int)num_double;
    cout << "num_int1 = " << num_int1 << endl;

    // function-style conversion from double to int using int() func
    int num_int2 = int(num_double);
    cout << "num_int2 = " << num_int2 << endl;

    return 0;
}