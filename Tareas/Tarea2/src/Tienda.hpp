#ifndef TIENDA_HPP
#define TIENDA_HPP

#include <iostream>
#include <vector>

#include "Producto.hpp"
#include "Cliente.hpp"

class Tienda {
    private:
        std::vector<Producto*> productosDisponibles;
        std::vector<Cliente*> clientes;

    public:
        ~Tienda();

        void agregarProducto(Producto *producto);

        void agregarCliente(Cliente* cliente);

        void procesarCompra(const std::string &nombreCliente) const;
};

#endif // TIENDA_HPP