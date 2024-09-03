#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <vector>
#include "Producto.hpp"

class Cliente {
    protected:
        std::string nombre;
        std::vector<Producto*> carrito;

    public:
        Cliente(const std::string &nombre);

        virtual ~Cliente();

        std::string getNombre() const;

        void agregarProducto(Producto *producto);

        virtual double calcularTotal() const;

        virtual double aplicarDescuento(double total) const = 0;

};

#endif // CLIENTE_HPP