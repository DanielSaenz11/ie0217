/**
 * @file InventarioTests.cpp
 * @brief Pruebas unitarias para la clase Inventario.
 * @details Este archivo contiene las pruebas unitarias para verificar las validaciones y el comportamiento
 * de la clase `Inventario`. Las pruebas abarcan casos de manejo de excepciones, operaciones con componentes,
 * y validaciones de entradas inválidas.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 15/11/2024
 */

#include <gtest/gtest.h>
#include "Inventario.hpp"
#include "Componente.hpp"

/**
 * @brief Verifica que no se pueda agregar un componente con cantidad negativa.
 * @details Comprueba que la función `agregarComponente` lance una excepción `std::invalid_argument`
 * cuando se intenta agregar un componente con una cantidad negativa.
 */
TEST(InventarioTest, AgregarCantidadNegativa) {
    Inventario inventario;
    ASSERT_THROW(inventario.agregarComponente("Inductor", -5, "Inductor", "10mH"), std::invalid_argument);
}

/**
 * @brief Verifica que no se pueda agregar un componente con nombre vacío.
 * @details Comprueba que la función `agregarComponente` lance una excepción `std::invalid_argument`
 * cuando se intenta agregar un componente con un nombre vacío.
 */
TEST(InventarioTest, AgregarComponenteNombreVacio) {
    Inventario inventario;
    ASSERT_THROW(inventario.agregarComponente("", 10, "Resistencia", "1k Ohm"), std::invalid_argument);
}

/**
 * @brief Verifica que no se pueda reducir una cantidad negativa de un componente.
 * @details Comprueba que la función `reducirComponente` lance una excepción `std::invalid_argument`
 * cuando se intenta reducir una cantidad negativa.
 */
TEST(InventarioTest, ReducirCantidadNegativa) {
    Inventario inventario;
    inventario.agregarComponente("Condensador", 10, "Capacitor", "100uF");
    ASSERT_THROW(inventario.reducirComponente("Capacitor", -5), std::invalid_argument);
}

/**
 * @brief Verifica que no se pueda reducir un componente que no existe.
 * @details Comprueba que la función `reducirComponente` lance una excepción `std::runtime_error`
 * cuando se intenta reducir un componente que no está presente en el inventario.
 */
TEST(InventarioTest, ReducirComponenteInexistente) {
    Inventario inventario;
    ASSERT_THROW(inventario.reducirComponente("Capacitor", 5), std::runtime_error);
}

/**
 * @brief Verifica que se pueda listar componentes cuando el inventario tiene elementos.
 * @details Comprueba que la función `listarComponentes` no lance excepciones cuando
 * el inventario tiene componentes y que se ejecute correctamente.
 */
TEST(InventarioTest, ListarComponentesInventarioConElementos) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", 10, "Resistencia", "1k Ohm");
    inventario.agregarComponente("Condensador", 5, "Capacitor", "100uF");

    // Asegurarse de que no se lanza una excepción y listarComponentes se ejecuta correctamente
    EXPECT_NO_THROW(inventario.listarComponentes());
}

/**
 * @brief Verifica que no se puedan listar componentes cuando el inventario está vacío.
 * @details Comprueba que la función `listarComponentes` lance una excepción `std::runtime_error`
 * cuando el inventario no contiene ningún componente.
 */
TEST(InventarioTest, ListarComponentesInventarioVacio) {
    Inventario inventario;
    ASSERT_THROW(inventario.listarComponentes(), std::runtime_error);
}

/**
 * @brief Verifica que no se pueda buscar un componente que no existe en el inventario.
 * @details Comprueba que la función `buscarComponente` lance una excepción `std::runtime_error`
 * cuando el componente buscado no está presente en el inventario.
 */
TEST(InventarioTest, BuscarComponenteNoEncontrado) {
    Inventario inventario;
    ASSERT_THROW(inventario.buscarComponente("Inductor"), std::runtime_error);
}


