#ifndef LIBRO_HPP
#define LIBRO_HPP

// Estructura para guardar la informacion de un libro
struct Libro {
    char titulo[100];
    char autor[100];
    char ISBN[13];
    int anioPublicacion;
};

#endif // LIBRO_HPP