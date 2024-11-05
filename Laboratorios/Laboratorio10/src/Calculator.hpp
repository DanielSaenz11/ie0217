/*
Header file que contiene la declaración de la clase Calculator

- add
- substract
- multiply
- divide
*/

#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

// Declaración de clase Calculator
class Calculator {
public:
    // Métodos para operaciones básicas
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
};

#endif // CALCULATOR_HPP