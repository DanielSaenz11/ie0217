#include "ClienteRegular.hpp"

using namespace std;

ClienteRegular::ClienteRegular(string &nombre) : Cliente(nombre) {}

double ClienteRegular::aplicarDescuento(double total) const {
    return total;
}