

#include <gtest/gtest.h>
#include "Inventario.hpp"
#include "Componente.hpp"

// Test funcional para agregar un componente nuevo y verificar sus propiedades
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

// Test para incrementar la cantidad de un componente existente
TEST(InventarioFunctionalTest, IncrementarCantidad) {
    Inventario inventario;
    inventario.agregarComponente("Condensador", 5, "Capacitor", "100uF");
    inventario.agregarComponente("Condensador", 10, "Capacitor", "100uF");

    const Componente& condensador = inventario.buscarComponente("Condensador");
    EXPECT_EQ(condensador.getCantidad(), 15);
}

// Test para reducir la cantidad de un componente existente
TEST(InventarioFunctionalTest, ReducirCantidadComponente) {
    Inventario inventario;
    inventario.agregarComponente("Inductor", 8, "Inductor", "10mH");

    // Reducir la cantidad existente
    EXPECT_TRUE(inventario.reducirComponente("Inductor", 3));
    
    // Verificar que la cantidad ha sido reducida correctamente
    const Componente& inductor = inventario.buscarComponente("Inductor");
    EXPECT_EQ(inductor.getCantidad(), 5);
}

// Test para intentar reducir una cantidad mayor a la disponible en el inventario
TEST(InventarioFunctionalTest, ReducirCantidadInsuficiente) {
    Inventario inventario;
    inventario.agregarComponente("Inductor", 8, "Inductor", "10mH");

    // Intentar reducir más de la cantidad disponible
    EXPECT_FALSE(inventario.reducirComponente("Inductor", 10));
}

// Test para listar componentes con un inventario lleno
TEST(InventarioFunctionalTest, ListarComponentesConElementos) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", 10, "Resistencia", "1k Ohm");
    inventario.agregarComponente("Condensador", 5, "Capacitor", "100uF");

    // Comprobar que no se lanza ninguna excepción y que listarComponentes se ejecuta correctamente
    EXPECT_NO_THROW(inventario.listarComponentes());
}