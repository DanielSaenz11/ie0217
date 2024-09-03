#include "ProductoDigital.hpp"

using namespace std;

ProductoDigital::ProductoDigital(const std::string &nombre, double precio, const std::string &id) : 
Producto(nombre, precio), id(id) {}

string ProductoDigital::getId() const {
    return id;
}
