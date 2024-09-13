#ifndef LISTACANCIONES_HPP
#define LISTACANCIONES_HPP

#include <string>
#include "NodoCanciones.hpp"

class ListaCanciones {

    private:
        Nodo *cabeza;

    public:
        // Constructor
        ListaCanciones();

        // Destructor
        ~ListaCanciones();

        // Insercion en la lista
        void insertarInicio(const Cancion& cancion);
        void insertarFinal(const Cancion& cancion);
        void insertarPosicion(const Cancion& cancion, int posicion);

        // Eliminar canciones
        void eliminarCancion(const std::string &nombre);

        // Modificar canciones
        void modificarCancion(const std::string &nombre);

        // Imprimir la lista de canciones
        void imprimirLista() const;

        // Buscar cancion por nombre
        Nodo* buscarCancion(const std::string &nombre) const;

};

#endif // LISTACANCIONES_HPP