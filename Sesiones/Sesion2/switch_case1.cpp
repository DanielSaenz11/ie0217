/**
 * Switch-case statement: Sirve para la toma de decisiones
 * 
 * En el codigo, se busca una coincidencia del caracter de varias operaciones matematicas
 * Si hay coincidencia, se ejecuta la operacion con los numeros ingresados
 * Si no hay, se muestra un mensaje de error
 */

#include <iostream>
using namespace std;

int main() {
    // Declaracion de las variables locales
    char oper;
    float num1, num2;

    // Ingreso de la operacion
    cout << "Enter an operation (+, -, *, /): ";
    cin >> oper;

    // Ingreso de dos numeros para operar
    cout << "Enter two numbers " << endl;
    cin >> num1 >> num2;

    // switch-case
    switch (oper) {
        case '+':
            // Suma
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            // Resta
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            // Multiplicacion
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            // Division
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;
        default:
            // En caso de que no se haya coincidencia con '+', '-', '*', '/'
            cout << "Error! The operator is not correct";
            break;
    }

    return 0;
}