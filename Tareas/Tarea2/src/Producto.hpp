#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <iostream>

class Producto {
    protected:
        std::string nombre;
        double precio;

    public:
        Producto(const std::string &nombre, double precio);

        virtual ~Producto() = default;

        double getPrecio() const;

        std::string getNombre() const;

};

#endif // PRODUCTO_HPP