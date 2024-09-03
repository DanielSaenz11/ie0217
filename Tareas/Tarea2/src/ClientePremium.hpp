#ifndef CLIENTE_PREMIUM_HPP
#define CLIENTE_PREMIUM_HPP

#include <iostream>
#include "Cliente.hpp"

class ClientePremium : public Cliente {
    private:
        double descuento;

    public:
        ClientePremium(std::string &nombre, double descuento);

        double aplicarDescuento(double total) const override;
};

#endif // CLIENTE_PREMIUM_HPP