/**
 * @file Cancion.cpp
 * @brief Archivo que contiene la definición de las funciones miembro de la clase Cancion.
 * 
 * @details En este source file se implementan las funciones miembro declaradas en el header file Cancion.hpp.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 14/09/2024
 */

#include "Cancion.hpp" // Incluir header file con las declaraciones

using namespace std;

// Definición del constructor de la clase Cancion: Se asignan los parámetros a cada uno de las variables miembro implementadas
Cancion::Cancion(const string &nombre, const string &artista, double duracion) : nombre(nombre), artista(artista), duracion(duracion) {}

/* Definición de funciones getters */

string Cancion::getNombre() const {
    return nombre;
}

string Cancion::getArtista() const {
    return artista;
}

double Cancion::getDuracion() const {
    return duracion;
}

/* Definición de funciones setters */

void Cancion::setNombre(const std::string &nombre) {
    this->nombre = nombre; // Uso de this para diferenciar del parámetro
}

void Cancion::setArtista(const std::string &artista) {
    this->artista = artista; // Uso de this para diferenciar del parámetro
}

void Cancion::setDuracion(double duracion) {
    this->duracion = duracion; // Uso de this para diferenciar del parámetro
}



