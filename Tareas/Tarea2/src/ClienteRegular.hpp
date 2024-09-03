#ifndef CLIENTE_REGULAR_HPP
#define CLIENTE_REGULAR_HPP

#include <iostream>
#include "Cliente.hpp"

class ClienteRegular : public Cliente {
    public:
        ClienteRegular(std::string &nombre);

        double aplicarDescuento(double total) const override;
};

#endif // CLIENTE_REGULAR_HPP