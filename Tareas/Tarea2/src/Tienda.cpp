#include "Tienda.hpp"

using namespace std;

Tienda::~Tienda() {
    for (Producto *producto : productosDisponibles) {
        delete producto;
    }
    for (Cliente *cliente : clientes) {
        delete cliente;
    }
}

void Tienda::agregarProducto(Producto *producto) {
    productosDisponibles.push_back(producto);
}

void Tienda::agregarCliente(Cliente *cliente) {
    clientes.push_back(cliente);
}

void Tienda::procesarCompra(const string &nombreCliente) const {
    Cliente* cliente = nullptr;

    for (Cliente* c : clientes) {
        if (c->getNombre() == nombreCliente) {
            cliente = c;
            break;
        }
    }

    if (cliente) {
        double total = cliente->calcularTotal();

        double totalConDescuento = cliente->aplicarDescuento(total);

        std::cout << "Cliente: " << nombreCliente << std::endl;
        std::cout << "Total sin descuento: $" << total << std::endl;
        std::cout << "Total con descuento: $" << totalConDescuento << std::endl;
        std::cout << "Productos en el carrito:" << std::endl;

        for (const Producto* producto : cliente->getCarrito()) {
            std::cout << "- " << producto->getNombre() << " ($" << producto->getPrecio() << ")" << std::endl;
        }
    }
    else {
        std::cout << "Cliente no encontrado." << std::endl;
    }
}