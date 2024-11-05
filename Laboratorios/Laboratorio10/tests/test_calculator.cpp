/*
Archivo que contiene las pruebas para las diferentes operaciones dentro de la Calculadora

- Suma
- Resta
- Multiplicación
- División
- División por cero
*/

#include <gtest/gtest.h>
#include "../src/Calculator.hpp"

Calculator calc; // Crear instancia de la calculadora

// Test para verificar el funcionamiento de la suma
TEST(CalculatorTests, Addition) {
    EXPECT_DOUBLE_EQ(calc.add(3.0, 4.0), 7.0);
}

// Test para verificar el funcionamiento de la resta
TEST(CalculatorTests, Subtraction) {
    EXPECT_DOUBLE_EQ(calc.subtract(10.0, 4.0), 6.0);
}

// Test para verificar el funcionamiento de la multiplicación
TEST(CalculatorTests, Multiplication) {
    EXPECT_DOUBLE_EQ(calc.multiply(3.0, 5.0), 15.0);
}

// Test para verificar el funcionamiento de la división
TEST(CalculatorTests, Division) {
    EXPECT_DOUBLE_EQ(calc.divide(10.0, 2.0), 5.0);
}

// Test para verificar el funcionamiento de la división por cero
TEST(CalculatorTests, DivisionByZero) {
    EXPECT_THROW(calc.divide(10.0, 0), std::invalid_argument);
}
