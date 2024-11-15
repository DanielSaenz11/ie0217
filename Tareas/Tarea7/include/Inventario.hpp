

#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "Componente.hpp"
#include <vector>
#include <string>

class Inventario {
    private:
        std::vector<Componente> componentes;

    public:
        void agregarComponente(const std::string& nombre, int cantidad, const std::string& categoria, const std::string& descripcion);

        bool reducirComponente(const std::string& nombre, int cantidad);

        void listarComponentes() const;

        const Componente& buscarComponente(const std::string& nombre) const;
};

#endif // INVENTARIO_HPP
