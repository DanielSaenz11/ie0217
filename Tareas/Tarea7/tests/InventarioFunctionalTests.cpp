/**
 * @file InventarioFunctionalTests.cpp
 * @brief Pruebas funcionales para la clase Inventario.
 * @details Este archivo contiene las pruebas funcionales para verificar el flujo completo de operaciones
 * de la clase `Inventario`. Las pruebas abarcan la adición, búsqueda, modificación y listado de componentes
 * en el inventario, asegurando que las operaciones se comporten correctamente en escenarios realistas.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 15/11/2024
 */


#include <gtest/gtest.h>
#include "Inventario.hpp"
#include "Componente.hpp"

/**
 * @brief Prueba funcional para agregar y buscar un componente en el inventario.
 * @details Verifica que un componente pueda ser agregado correctamente al inventario y que sus propiedades
 * coincidan con los valores proporcionados. También valida que la operación de búsqueda no lance excepciones.
 */
TEST(InventarioFunctionalTest, AgregarBuscarComponentes) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", 10, "Resistencia", "1k Ohm");

    // Asegura que no se lance ninguna excepción al buscar el componente
    EXPECT_NO_THROW({
        const Componente& encontrado = inventario.buscarComponente("Resistencia");

        // Verificar que el componente tiene los valores correctos
        EXPECT_EQ(encontrado.getNombre(), "Resistencia");
        EXPECT_EQ(encontrado.getCantidad(), 10);
        EXPECT_EQ(encontrado.getCategoria(), "Resistencia");
        EXPECT_EQ(encontrado.getDescripcion(), "1k Ohm");
    });
}

/**
 * @brief Prueba funcional para incrementar la cantidad de un componente existente.
 * @details Comprueba que al agregar un componente con el mismo nombre, su cantidad se incremente correctamente.
 */
TEST(InventarioFunctionalTest, IncrementarCantidad) {
    Inventario inventario;
    inventario.agregarComponente("Condensador", 5, "Capacitor", "100uF");
    inventario.agregarComponente("Condensador", 10, "Capacitor", "100uF");

    const Componente& condensador = inventario.buscarComponente("Condensador");
    EXPECT_EQ(condensador.getCantidad(), 15);
}

/**
 * @brief Prueba funcional para reducir la cantidad de un componente existente.
 * @details Verifica que la cantidad de un componente se reduzca correctamente cuando hay suficiente stock.
 */
TEST(InventarioFunctionalTest, ReducirCantidadComponente) {
    Inventario inventario;
    inventario.agregarComponente("Inductor", 8, "Inductor", "10mH");

    // Reducir la cantidad existente
    EXPECT_TRUE(inventario.reducirComponente("Inductor", 3));
    
    // Verificar que la cantidad ha sido reducida correctamente
    const Componente& inductor = inventario.buscarComponente("Inductor");
    EXPECT_EQ(inductor.getCantidad(), 5);
}

/**
 * @brief Prueba funcional para intentar reducir una cantidad mayor a la disponible.
 * @details Comprueba que no sea posible reducir más cantidad de la que está disponible en el inventario,
 * y que la función devuelva `false` en estos casos.
 */
TEST(InventarioFunctionalTest, ReducirCantidadInsuficiente) {
    Inventario inventario;
    inventario.agregarComponente("Inductor", 8, "Inductor", "10mH");

    // Intentar reducir más de la cantidad disponible
    EXPECT_FALSE(inventario.reducirComponente("Inductor", 10));
}

/**
 * @brief Prueba funcional para listar componentes en un inventario con elementos.
 * @details Comprueba que la función `listarComponentes` se ejecute correctamente cuando el inventario tiene
 * elementos, y que no lance excepciones.
 */
TEST(InventarioFunctionalTest, ListarComponentesConElementos) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", 10, "Resistencia", "1k Ohm");
    inventario.agregarComponente("Condensador", 5, "Capacitor", "100uF");

    // Comprobar que no se lanza ninguna excepción y que listarComponentes se ejecuta correctamente
    EXPECT_NO_THROW(inventario.listarComponentes());
}