

#include <gtest/gtest.h>
#include "Circuitos.hpp"

/* -------------------- Valores válidos -------------------- */

// Test para resistencia en serie con valores válidos
TEST(CircuitosTest, ResistenciaSerie) {
    std::vector<double> resistencias = {10, 20, 30};
    ASSERT_DOUBLE_EQ(resistenciaSerie(resistencias), 60.0);
}

// Test para resistencia en paralelo con valores válidos
TEST(CircuitosTest, ResistenciaParalelo) {
    std::vector<double> resistencias = {10, 20, 30};
    ASSERT_NEAR(resistenciaParalelo(resistencias), 5.4545, 0.0001);
}

// Test para capacitancia en serie con valores válidos
TEST(CircuitosTest, CapacitanciaSerie) {
    std::vector<double> capacitancias = {10, 20, 30};
    ASSERT_NEAR(capacitanciaSerie(capacitancias), 5.4545, 0.0001);
}

// Test para capacitancia en paralelo con valores válidos
TEST(CircuitosTest, CapacitanciaParalelo) {
    std::vector<double> capacitancias = {10, 20, 30};
    ASSERT_DOUBLE_EQ(capacitanciaParalelo(capacitancias), 60.0);
}

// Test para inductancia en serie con valores válidos
TEST(CircuitosTest, InductanciaSerie) {
    std::vector<double> inductancias = {10, 20, 30};
    ASSERT_DOUBLE_EQ(inductanciaSerie(inductancias), 60.0);
}

// Test para inductancia en paralelo con valores válidos
TEST(CircuitosTest, InductanciaParalelo) {
    std::vector<double> inductancias = {10, 20, 30};
    ASSERT_NEAR(inductanciaParalelo(inductancias), 5.4545, 0.0001);
}

/* ------------------- Valores inválidos ------------------- */

// Test para resistencia en serie con valor no válido
TEST(CircuitosTest, ResistenciaSerieValorInvalido) {
    std::vector<double> resistencias = {10, -5, 30};
    ASSERT_THROW(resistenciaSerie(resistencias), std::invalid_argument);
}

// Test para resistencia en paralelo con valor no válido
TEST(CircuitosTest, ResistenciaParaleloValorInvalido) {
    std::vector<double> resistencias = {10, 0, 30};
    ASSERT_THROW(resistenciaParalelo(resistencias), std::invalid_argument);
}

// Test para capacitancia en serie con valor no válido
TEST(CircuitosTest, CapacitanciaSerieValorInvalido) {
    std::vector<double> capacitancias = {15, -3, 20};
    ASSERT_THROW(capacitanciaSerie(capacitancias), std::invalid_argument);
}

// Test para capacitancia en paralelo con valor no válido
TEST(CircuitosTest, CapacitanciaParaleloValorInvalido) {
    std::vector<double> capacitancias = {10, 0, 30};
    ASSERT_THROW(capacitanciaParalelo(capacitancias), std::invalid_argument);
}

// Test para inductancia en serie con valor no válido
TEST(CircuitosTest, InductanciaSerieValorInvalido) {
    std::vector<double> inductancias = {10, -5, 30};
    ASSERT_THROW(inductanciaSerie(inductancias), std::invalid_argument);
}

// Test para inductancia en paralelo con valor no válido
TEST(CircuitosTest, InductanciaParaleloValorInvalido) {
    std::vector<double> inductancias = {10, 0, 30};
    ASSERT_THROW(inductanciaParalelo(inductancias), std::invalid_argument);
}

/* ------------------- Vector vacío ------------------- */

// Test para resistencia en serie con vector vacío
TEST(CircuitosTest, ResistenciaSerieVectorVacio) {
    std::vector<double> resistencias;
    ASSERT_THROW(resistenciaSerie(resistencias), std::invalid_argument);
}

// Test para resistencia en paralelo con vector vacío
TEST(CircuitosTest, ResistenciaParaleloVectorVacio) {
    std::vector<double> resistencias;
    ASSERT_THROW(resistenciaParalelo(resistencias), std::invalid_argument);
}

// Test para capacitancia en serie con vector vacío
TEST(CircuitosTest, CapacitanciaSerieVectorVacio) {
    std::vector<double> capacitancias;
    ASSERT_THROW(capacitanciaSerie(capacitancias), std::invalid_argument);
}

// Test para capacitancia en paralelo con vector vacío
TEST(CircuitosTest, CapacitanciaParaleloVectorVacio) {
    std::vector<double> capacitancias;
    ASSERT_THROW(capacitanciaParalelo(capacitancias), std::invalid_argument);
}

// Test para inductancia en serie con vector vacío
TEST(CircuitosTest, InductanciaSerieVectorVacio) {
    std::vector<double> inductancias;
    ASSERT_THROW(inductanciaSerie(inductancias), std::invalid_argument);
}

// Test para inductancia en paralelo con vector vacío
TEST(CircuitosTest, InductanciaParaleloVectorVacio) {
    std::vector<double> inductancias;
    ASSERT_THROW(inductanciaParalelo(inductancias), std::invalid_argument);
}
