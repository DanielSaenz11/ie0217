

#ifndef COMPONENTE_HPP
#define COMPONENTE_HPP

#include <string>

class Componente {
    private:
        std::string nombre;
        int cantidad;
        std::string categoria;
        std::string descripcion;

    public:
        Componente(const std::string& nombre, int cantidad, const std::string& categoria, const std::string& descripcion);

        void agregarComponente(int cantidad);

        bool reducirComponente(int cantidad);

        const std::string getNombre() const;

        const std::string getCategoria() const;

        int getCantidad() const;

        const std::string getDescripcion() const;
};

#endif // COMPONENTE_HPP
