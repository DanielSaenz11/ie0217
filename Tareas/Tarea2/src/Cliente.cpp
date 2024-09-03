#include "Cliente.hpp"

using namespace std;

Cliente::Cliente(const string &nombre) : nombre(nombre) {}

Cliente::~Cliente() {
    for (Producto *producto : carrito) {
        delete producto;
    }
}

string Cliente::getNombre() const {
    return this->nombre;
}

void Cliente::agregarProducto(Producto *producto) {
    carrito.push_back(producto);
}

double Cliente::calcularTotal() const {
    double total = 0.0;
    for (const Producto *producto : carrito) {
        total += producto->getPrecio();
    }
    return total;
}


