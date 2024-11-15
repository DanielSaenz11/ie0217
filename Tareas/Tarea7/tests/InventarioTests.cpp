

#include <gtest/gtest.h>
#include "Inventario.hpp"
#include "Componente.hpp"

// Test para agregar cantidad negativa de componente
TEST(InventarioTest, AgregarCantidadNegativa) {
    Inventario inventario;
    ASSERT_THROW(inventario.agregarComponente("Inductor", -5, "Inductor", "10mH"), std::invalid_argument);
}

// Test para agregar un componente con nombre vacío
TEST(InventarioTest, AgregarComponenteNombreVacio) {
    Inventario inventario;
    ASSERT_THROW(inventario.agregarComponente("", 10, "Resistencia", "1k Ohm"), std::invalid_argument);
}

// Test para reducir cantidad negativa de un componente
TEST(InventarioTest, ReducirCantidadNegativa) {
    Inventario inventario;
    inventario.agregarComponente("Condensador", 10, "Capacitor", "100uF");
    ASSERT_THROW(inventario.reducirComponente("Capacitor", -5), std::invalid_argument);
}

// Test para reducir un componente que no existe
TEST(InventarioTest, ReducirComponenteInexistente) {
    Inventario inventario;
    ASSERT_THROW(inventario.reducirComponente("Capacitor", 5), std::runtime_error);
}

// Test para listar componentes cuando el inventario tiene elementos
TEST(InventarioTest, ListarComponentesInventarioConElementos) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", 10, "Resistencia", "1k Ohm");
    inventario.agregarComponente("Condensador", 5, "Capacitor", "100uF");

    // Asegurarse de que no se lanza una excepción y listarComponentes se ejecuta correctamente
    EXPECT_NO_THROW(inventario.listarComponentes());
}

// Test para listar componentes cuando el inventario está vacío
TEST(InventarioTest, ListarComponentesInventarioVacio) {
    Inventario inventario;
    ASSERT_THROW(inventario.listarComponentes(), std::runtime_error);
}

// Test para buscar un componente que no existe en el inventario
TEST(InventarioTest, BuscarComponenteNoEncontrado) {
    Inventario inventario;
    ASSERT_THROW(inventario.buscarComponente("Inductor"), std::runtime_error);
}


