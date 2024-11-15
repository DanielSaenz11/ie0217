/**
 * @file ComponenteTests.cpp
 * @brief Pruebas unitarias para la clase Componente.
 * @details Este archivo contiene las pruebas unitarias para verificar el correcto funcionamiento
 * de la clase `Componente`. Las pruebas cubren la creación de componentes, la adición y reducción
 * de cantidades, y la validación de entradas inválidas como nombres vacíos y cantidades negativas.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 15/11/2024
 */

#include <gtest/gtest.h>
#include "Componente.hpp"

/**
 * @brief Verifica que un componente se cree correctamente con parámetros válidos.
 * @details Comprueba que todos los atributos del componente (nombre, cantidad, categoría, descripción)
 * se inicialicen con los valores proporcionados al constructor.
 */
TEST(ComponenteTest, CrearComponente) {
    Componente resistencia("Resistencia",10, "Resistencia", "1k Ohm");
    EXPECT_EQ(resistencia.getNombre(), "Resistencia");
    EXPECT_EQ(resistencia.getCategoria(), "Resistencia");
    EXPECT_EQ(resistencia.getCantidad(), 10);
    EXPECT_EQ(resistencia.getDescripcion(), "1k Ohm");
}

/**
 * @brief Verifica que no se pueda crear un componente con una cantidad inicial negativa.
 * @details Comprueba que el constructor lance una excepción `std::invalid_argument` cuando la cantidad
 * inicial es menor o igual a cero.
 */
TEST(ComponenteTest, CrearComponenteCantidadNegativa) {
    ASSERT_THROW(Componente("Resistencia", -10, "Resistencia", "1k Ohm"), std::invalid_argument);
}

/**
 * @brief Verifica que no se pueda agregar una cantidad negativa a un componente existente.
 * @details Comprueba que el método `agregarComponente` lance una excepción `std::invalid_argument`
 * cuando la cantidad proporcionada es negativa.
 */
TEST(ComponenteTest, AgregarCantidadNegativaComponente) {
    Componente resistencia("Resistencia", 10, "Resistencia", "1k Ohm");
    ASSERT_THROW(resistencia.agregarComponente(-5), std::invalid_argument);
}

/**
 * @brief Verifica que no se pueda crear un componente con un nombre vacío.
 * @details Comprueba que el constructor lance una excepción `std::invalid_argument` cuando
 * el nombre proporcionado es una cadena vacía.
 */
TEST(ComponenteTest, CrearComponenteNombreVacio) {
    ASSERT_THROW(Componente("", 10, "Resistencia", "1k Ohm"), std::invalid_argument);
}

/**
 * @brief Verifica que se pueda reducir correctamente la cantidad de un componente.
 * @details Comprueba que el método `reducirComponente` disminuya la cantidad del componente
 * cuando hay suficiente stock disponible.
 */
TEST(ComponenteTest, ReducirCantidad) {
    Componente resistencia("Resistencia", 10, "Resistencia", "1k Ohm");
    EXPECT_TRUE(resistencia.reducirComponente(5));
    EXPECT_EQ(resistencia.getCantidad(), 5);
}

/**
 * @brief Verifica que no se pueda reducir una cantidad negativa de un componente.
 * @details Comprueba que el método `reducirComponente` lance una excepción `std::invalid_argument`
 * cuando se proporciona una cantidad negativa.
 */
TEST(ComponenteTest, ReducirCantidadNegativaComponente) {
    Componente resistencia("Resistencia", 10, "Resistencia", "1k Ohm");
    ASSERT_THROW(resistencia.reducirComponente(-5), std::invalid_argument);
}

/**
 * @brief Verifica que no se pueda reducir más cantidad de la disponible en un componente.
 * @details Comprueba que el método `reducirComponente` devuelva `false` cuando se intenta
 * reducir una cantidad mayor a la cantidad actual del componente.
 */
TEST(ComponenteTest, ReducirCantidadInsuficiente) {
    Componente resistencia("Resistencia", 10, "Resistencia", "1k Ohm");
    EXPECT_FALSE(resistencia.reducirComponente(15));
}

