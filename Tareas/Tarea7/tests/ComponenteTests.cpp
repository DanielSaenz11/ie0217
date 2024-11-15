

#include <gtest/gtest.h>
#include "Componente.hpp"

// Test para crear un componente de forma correcta
TEST(ComponenteTest, CrearComponente) {
    Componente resistencia("Resistencia",10, "Resistencia", "1k Ohm");
    EXPECT_EQ(resistencia.getNombre(), "Resistencia");
    EXPECT_EQ(resistencia.getCategoria(), "Resistencia");
    EXPECT_EQ(resistencia.getCantidad(), 10);
    EXPECT_EQ(resistencia.getDescripcion(), "1k Ohm");
}

// Test para crear un componente con cantidad negativa
TEST(ComponenteTest, CrearComponenteCantidadNegativa) {
    ASSERT_THROW(Componente("Resistencia", -10, "Resistencia", "1k Ohm"), std::invalid_argument);
}

// Test para agregar una cantidad negativa a un componente
TEST(ComponenteTest, AgregarCantidadNegativaComponente) {
    Componente resistencia("Resistencia", 10, "Resistencia", "1k Ohm");
    ASSERT_THROW(resistencia.agregarComponente(-5), std::invalid_argument);
}

// Test para verificar que no se puede crear un componente con nombre vacío
TEST(ComponenteTest, CrearComponenteNombreVacio) {
    ASSERT_THROW(Componente("", 10, "Resistencia", "1k Ohm"), std::invalid_argument);
}

// Test para reducir una cantidad correctamente
TEST(ComponenteTest, ReducirCantidad) {
    Componente resistencia("Resistencia", 10, "Resistencia", "1k Ohm");
    EXPECT_TRUE(resistencia.reducirComponente(5));
    EXPECT_EQ(resistencia.getCantidad(), 5); // La cantidad restante debería ser 5
}

// Test para reducir una cantidad negativa para un componente existente
TEST(ComponenteTest, ReducirCantidadNegativaComponente) {
    Componente resistencia("Resistencia", 10, "Resistencia", "1k Ohm");
    ASSERT_THROW(resistencia.reducirComponente(-5), std::invalid_argument);
}

// Test para reducir más cantidad de la disponible en un componente
TEST(ComponenteTest, ReducirCantidadInsuficiente) {
    Componente resistencia("Resistencia", 10, "Resistencia", "1k Ohm");
    EXPECT_FALSE(resistencia.reducirComponente(15));
}

