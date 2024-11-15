/**
 * @file CircuitosTests.cpp
 * @brief Pruebas unitarias para el módulo de cálculos de circuitos.
 * @details Este archivo contiene las pruebas unitarias para verificar el correcto funcionamiento
 * de las funciones del módulo de cálculos de circuitos, incluyendo cálculos de resistencia, 
 * capacitancia e inductancia en configuraciones de serie y paralelo. También se incluye la función
 * para capacitancia equivalente combinando serie y paralelo, siguiendo un enfoque TDD.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 15/11/2024
 */

#include <gtest/gtest.h>
#include "Circuitos.hpp"

/* -------------------- Valores válidos -------------------- */

/**
 * @brief Verifica el cálculo de resistencia en serie con valores válidos.
 * @details Comprueba que la función `resistenciaSerie` sume correctamente las resistencias
 * cuando se proporcionan valores positivos en el vector.
 */
TEST(CircuitosTest, ResistenciaSerie) {
    std::vector<double> resistencias = {10, 20, 30};
    ASSERT_DOUBLE_EQ(resistenciaSerie(resistencias), 60.0);
}

/**
 * @brief Verifica el cálculo de resistencia en paralelo con valores válidos.
 * @details Comprueba que la función `resistenciaParalelo` calcule correctamente la resistencia equivalente
 * cuando se proporcionan valores positivos en el vector.
 */
TEST(CircuitosTest, ResistenciaParalelo) {
    std::vector<double> resistencias = {10, 20, 30};
    ASSERT_NEAR(resistenciaParalelo(resistencias), 5.4545, 0.0001);
}

/**
 * @brief Verifica el cálculo de capacitancia en serie con valores válidos.
 * @details Comprueba que la función `capacitanciaSerie` calcule correctamente la capacitancia equivalente
 * en serie cuando se proporcionan valores positivos en el vector.
 */
TEST(CircuitosTest, CapacitanciaSerie) {
    std::vector<double> capacitancias = {10, 20, 30};
    ASSERT_NEAR(capacitanciaSerie(capacitancias), 5.4545, 0.0001);
}

/**
 * @brief Verifica el cálculo de capacitancia en paralelo con valores válidos.
 * @details Comprueba que la función `capacitanciaParalelo` calcule correctamente la suma de las capacitancias
 * en paralelo cuando se proporcionan valores positivos en el vector.
 */
TEST(CircuitosTest, CapacitanciaParalelo) {
    std::vector<double> capacitancias = {10, 20, 30};
    ASSERT_DOUBLE_EQ(capacitanciaParalelo(capacitancias), 60.0);
}

/**
 * @brief Verifica el cálculo de inductancia en serie con valores válidos.
 * @details Comprueba que la función `inductanciaSerie` sume correctamente las inductancias
 * cuando se proporcionan valores positivos en el vector.
 */
TEST(CircuitosTest, InductanciaSerie) {
    std::vector<double> inductancias = {10, 20, 30};
    ASSERT_DOUBLE_EQ(inductanciaSerie(inductancias), 60.0);
}

/**
 * @brief Verifica el cálculo de inductancia en paralelo con valores válidos.
 * @details Comprueba que la función `inductanciaParalelo` calcule correctamente la inductancia equivalente
 * cuando se proporcionan valores positivos en el vector.
 */
TEST(CircuitosTest, InductanciaParalelo) {
    std::vector<double> inductancias = {10, 20, 30};
    ASSERT_NEAR(inductanciaParalelo(inductancias), 5.4545, 0.0001);
}

/* ------------------- Valores inválidos ------------------- */

/**
 * @brief Verifica que resistencia en serie lance una excepción para valores inválidos.
 * @details Comprueba que la función `resistenciaSerie` lance una excepción `std::invalid_argument`
 * si el vector contiene valores negativos.
 */
TEST(CircuitosTest, ResistenciaSerieValorInvalido) {
    std::vector<double> resistencias = {10, -5, 30};
    ASSERT_THROW(resistenciaSerie(resistencias), std::invalid_argument);
}

/**
 * @brief Verifica que resistencia en paralelo lance una excepción para valores inválidos.
 * @details Comprueba que la función `resistenciaParalelo` lance una excepción `std::invalid_argument`
 * si el vector contiene valores no positivos.
 */
TEST(CircuitosTest, ResistenciaParaleloValorInvalido) {
    std::vector<double> resistencias = {10, 0, 30};
    ASSERT_THROW(resistenciaParalelo(resistencias), std::invalid_argument);
}

/**
 * @brief Verifica que capacitancia en serie lance una excepción para valores negativos.
 * @details Comprueba que la función `capacitanciaSerie` lance una excepción `std::invalid_argument`
 * si el vector contiene valores negativos.
 */
TEST(CircuitosTest, CapacitanciaSerieValorInvalido) {
    std::vector<double> capacitancias = {15, -3, 20};
    ASSERT_THROW(capacitanciaSerie(capacitancias), std::invalid_argument);
}

/**
 * @brief Verifica que capacitancia en paralelo lance una excepción para valores no válidos.
 * @details Comprueba que la función `capacitanciaParalelo` lance una excepción `std::invalid_argument`
 * si el vector contiene valores no positivos.
 */
TEST(CircuitosTest, CapacitanciaParaleloValorInvalido) {
    std::vector<double> capacitancias = {10, 0, 30};
    ASSERT_THROW(capacitanciaParalelo(capacitancias), std::invalid_argument);
}

/**
 * @brief Verifica que inductancia en serie lance una excepción para valores negativos.
 * @details Comprueba que la función `inductanciaSerie` lance una excepción `std::invalid_argument`
 * si el vector contiene valores negativos.
 */
TEST(CircuitosTest, InductanciaSerieValorInvalido) {
    std::vector<double> inductancias = {10, -5, 30};
    ASSERT_THROW(inductanciaSerie(inductancias), std::invalid_argument);
}

/**
 * @brief Verifica que inductancia en paralelo lance una excepción para valores no válidos.
 * @details Comprueba que la función `inductanciaParalelo` lance una excepción `std::invalid_argument`
 * si el vector contiene valores no positivos.
 */
TEST(CircuitosTest, InductanciaParaleloValorInvalido) {
    std::vector<double> inductancias = {10, 0, 30};
    ASSERT_THROW(inductanciaParalelo(inductancias), std::invalid_argument);
}

/* ------------------- Vector vacío ------------------- */

/**
 * @brief Verifica que resistencia en serie lance una excepción para un vector vacío.
 * @details Comprueba que la función `resistenciaSerie` lance una excepción `std::invalid_argument`
 * si el vector de resistencias está vacío.
 */
TEST(CircuitosTest, ResistenciaSerieVectorVacio) {
    std::vector<double> resistencias;
    ASSERT_THROW(resistenciaSerie(resistencias), std::invalid_argument);
}

/**
 * @brief Verifica que resistencia en paralelo lance una excepción para un vector vacío.
 * @details Comprueba que la función `resistenciaParalelo` lance una excepción `std::invalid_argument`
 * si el vector de resistencias está vacío.
 */
TEST(CircuitosTest, ResistenciaParaleloVectorVacio) {
    std::vector<double> resistencias;
    ASSERT_THROW(resistenciaParalelo(resistencias), std::invalid_argument);
}

/**
 * @brief Verifica que capacitancia en serie lance una excepción para un vector vacío.
 * @details Comprueba que la función `capacitanciaSerie` lance una excepción `std::invalid_argument`
 * si el vector de capacitancias está vacío.
 */
TEST(CircuitosTest, CapacitanciaSerieVectorVacio) {
    std::vector<double> capacitancias;
    ASSERT_THROW(capacitanciaSerie(capacitancias), std::invalid_argument);
}

/**
 * @brief Verifica que capacitancia en paralelo lance una excepción para un vector vacío.
 * @details Comprueba que la función `capacitanciaParalelo` lance una excepción `std::invalid_argument`
 * si el vector de capacitancias está vacío.
 */
TEST(CircuitosTest, CapacitanciaParaleloVectorVacio) {
    std::vector<double> capacitancias;
    ASSERT_THROW(capacitanciaParalelo(capacitancias), std::invalid_argument);
}

/**
 * @brief Verifica que inductancia en serie lance una excepción para un vector vacío.
 * @details Comprueba que la función `inductanciaSerie` lance una excepción `std::invalid_argument`
 * si el vector de inductancias está vacío.
 */
TEST(CircuitosTest, InductanciaSerieVectorVacio) {
    std::vector<double> inductancias;
    ASSERT_THROW(inductanciaSerie(inductancias), std::invalid_argument);
}

/**
 * @brief Verifica que inductancia en paralelo lance una excepción para un vector vacío.
 * @details Comprueba que la función `inductanciaParalelo` lance una excepción `std::invalid_argument`
 * si el vector de inductancias está vacío.
 */
TEST(CircuitosTest, InductanciaParaleloVectorVacio) {
    std::vector<double> inductancias;
    ASSERT_THROW(inductanciaParalelo(inductancias), std::invalid_argument);
}

/* ------------------- Tests TDD ------------------- */

/**
 * @brief Verifica el cálculo de capacitancia equivalente combinando serie y paralelo.
 * @details Comprueba un caso válido con dos grupos de capacitancias, calculando primero en paralelo y luego en serie.
 */
TEST(CircuitosTest, CapacitanciaEquivalenteSerieParalelo_CasoValido) {
    // Dos grupos de capacitancias
    std::vector<std::vector<double>> gruposCapacitancias = {
        {10.0, 20.0},  // Primer grupo en paralelo
        {30.0, 40.0}   // Segundo grupo en paralelo
    };

    // Paralelo: 10 + 20 = 30
    // Paralelo: 30 + 40 = 70
    // Serie: 1 / (1/30 + 1/70) = 21
    ASSERT_NEAR(capacitanciaEquivalenteSerieParalelo(gruposCapacitancias), 21.0, 0.01);
}

/**
 * @brief Verifica que la función lance una excepción para un vector vacío.
 * @details Comprueba que la función `capacitanciaEquivalenteSerieParalelo` lance una excepción `std::invalid_argument`
 * si no se proporcionan grupos de capacitancias.
 */
TEST(CircuitosTest, CapacitanciaEquivalenteSerieParalelo_VectorVacio) {
    std::vector<std::vector<double>> gruposCapacitancias;

    ASSERT_THROW(capacitanciaEquivalenteSerieParalelo(gruposCapacitancias), std::invalid_argument);
}

/**
 * @brief Verifica que la función lance una excepción para valores negativos.
 * @details Comprueba que la función `capacitanciaEquivalenteSerieParalelo` lance una excepción `std::invalid_argument`
 * si algún grupo contiene valores negativos.
 */
TEST(CircuitosTest, CapacitanciaEquivalenteSerieParalelo_ValoresNegativos) {
    // Un grupo contiene un valor negativo
    std::vector<std::vector<double>> gruposCapacitancias = {
        {10.0, -20.0}, // Valor negativo
        {30.0, 40.0}
    };
    ASSERT_THROW(capacitanciaEquivalenteSerieParalelo(gruposCapacitancias), std::invalid_argument);
}

/**
 * @brief Verifica el cálculo de capacitancia para un solo grupo.
 * @details Comprueba que la función `capacitanciaEquivalenteSerieParalelo` calcule correctamente
 * la capacitancia equivalente en paralelo si solo se proporciona un grupo.
 */
TEST(CircuitosTest, CapacitanciaEquivalenteSerieParalelo_UnSoloGrupo) {
    std::vector<std::vector<double>> gruposCapacitancias = {
        {10.0, 20.0, 30.0}
    };

    // Paralelo: 10 + 20 + 30 = 60
    ASSERT_NEAR(capacitanciaEquivalenteSerieParalelo(gruposCapacitancias), 60.0, 0.01);
}