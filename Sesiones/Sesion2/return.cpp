// Uso de return: Programa que suma dos numeros por medio de la funcion add()

#include <iostream>
using namespace std;

/**
 * @brief Funcion que suma dos numeros enteros
 * @param a Primer sumando
 * @param b Segundo sumando
 * @return Suma de a y b
 */
int add(int a, int b) {
    return (a+b);
}

int main() {
    
    // Declaracion de variable sum
    int sum;

    // Llamada de add() y se guarda su valor retornado en sum
    sum = add(100, 78);

    cout << "100 + 78 = " << sum << endl;

    return 0;

}