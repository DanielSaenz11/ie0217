#include "ClientePremium.hpp"

using namespace std;

ClientePremium::ClientePremium(string &nombre, double descuento) : Cliente(nombre), descuento(descuento) {}

double ClientePremium::aplicarDescuento(double total) const {
    return ((1 - descuento) * total);
}