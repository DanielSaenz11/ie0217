
#include "Cancion.hpp"

using namespace std;

// Constructor
Cancion::Cancion(const string &nombre, const string &artista, double duracion) : nombre(nombre), artista(artista), duracion(duracion) {}

// Getters

string Cancion::getNombre() const {
    return nombre;
}

string Cancion::getArtista() const {
    return artista;
}

double Cancion::getDuracion() const {
    return duracion;
}

void Cancion::setNombre(const std::string &nombre) {
    this->nombre = nombre; // Uso de this para diferenciar del parámetro
}

void Cancion::setArtista(const std::string &artista) {
    this->artista = artista; // Uso de this para diferenciar del parámetro
}

void Cancion::setDuracion(double duracion) {
    this->duracion = duracion; // Uso de this para diferenciar del parámetro
}



