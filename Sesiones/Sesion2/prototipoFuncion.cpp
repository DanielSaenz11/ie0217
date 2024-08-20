/**
 * Se declara el prototipo de la funcion antes de main
 * returnType func_name(parameterType1, parameterType2, ...);
 * 
 * La definicion de la funcion va despues de main
 */

#include <iostream>
using namespace std;

// Prototipo de la funcion
int add(int, int);

int main() {
    int sum;

    sum = add(100, 78);

    cout << "100 + 78 = " << sum << endl;

    return 0;
}

// Definicion de la funcion

/**
 * @brief Funcion que suma dos numeros enteros
 * @param a Primer sumando
 * @param b Segundo sumando
 * @return Suma de a y b
 */
int add(int a, int b) {
    return (a+b);
}