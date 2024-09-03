#ifndef PRODUCTO_DIGITAL_HPP
#define PRODUCTO_DIGITAL_HPP

#include "Producto.hpp"

class ProductoDigital : public Producto {
    private:
        std::string id;

    public:
        ProductoDigital(const std::string &nombre, double precio, const std::string &id);

        std::string getId() const;
};

#endif // PRODUCTO_DIGITAL_HPP