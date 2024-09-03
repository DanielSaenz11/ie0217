#ifndef PRODUCTO_FISICO_HPP
#define PRODUCTO_FISICO_HPP

#include "Producto.hpp"

class ProductoFisico : public Producto {
    private:
        double peso;

    public:
        ProductoFisico(const std::string &nombre, double precio, double peso);

        double getPeso() const;
};

#endif // PRODUCTO_FISICO_HPP