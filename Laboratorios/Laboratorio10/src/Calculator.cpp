/*
Source file donde se definen los métodos de la Calculadora correspondiente a:

- add
- substract
- multiply
- divide
*/

#include "Calculator.hpp"
#include <stdexcept>  // Para lanzar excepciones

// Definición de método add (suma)
double Calculator::add(double a, double b) {
    return a + b;
}

// Definición de método substract (resta)
double Calculator::subtract(double a, double b) {
    return a - b;
}

// Definición de método multiply (multiplicación)
double Calculator::multiply(double a, double b) {
    return a * b;
}

// Definición de método divide (división)
double Calculator::divide(double a, double b) {
    // En el caso de división por 0
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}