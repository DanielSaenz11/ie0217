#ifndef CANCION_HPP
#define CANCION_HPP

#include <string>

class Cancion {
    private:
        std::string nombre;
        std::string artista;
        double duracion; // Minutos

    public:
        // Constructor
        Cancion(const std::string &nombre, const std::string &artista, double duracion);

        // Getters
        std::string getNombre() const;
        std::string getArtista() const;
        double getDuracion() const;

        // Setters
        void setNombre(const std::string &nombre);
        void setArtista(const std::string &artista);
        void setDuracion(double duracion);
};

#endif // CANCION_HPP