#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

// Incluir definicion de estructura libro
#include "libro.hpp"

void agregarLibro(Libro libros[], int &cantidadLibros);

void buscarLibroPorTitulo(Libro libros[], int cantidadLibros);

void buscarLibroPorISBN(Libro libros[], int cantidadLibros);

void mostrarLibros(Libro libros[], int cantidadLibros);

void eliminarLibros(Libro libros[], int &cantidadLibros);

#endif // FUNCIONES_HPP