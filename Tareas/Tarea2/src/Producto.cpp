#include "Producto.hpp"

using namespace std;

Producto::Producto(const std::string &nombre, double precio) : nombre(nombre), precio(precio) {}

double Producto::getPrecio() const {
    return precio;
}

string Producto::getNombre() const {
    return nombre;
}