#include "ProductoFisico.hpp"

using namespace std;

ProductoFisico::ProductoFisico(const std::string &nombre, double precio, double peso) :
Producto(nombre, precio), peso(peso) {}

double ProductoFisico::getPeso() const {
    return peso;
}
