// Incluir las librerías
#include <iostream>
#include "funciones.hpp"

using namespace std;

enum opciones_menu {
    opt_agregarLibro = 1,
    opt_buscarLibroTitulo,
    opt_buscarLibroISBN,
    opt_mostrarLibros,
    opt_eliminarLibros,
    opt_salir
};

// Declarar cantidad máxima de libros para el arreglo
const int MAX_LIBROS = 100;

int main() {

    // Declarar la biblioteca de libros
    Libro libros[MAX_LIBROS];
    
    // Libros almacenados
    int cantidadLibros = 0;

    // Opción ingresada por el usuario
    int opcion;

    do {
        // Mostrar menú del programa
        cout << "\n Sistema de Gestión de Libros\n"; 
        cout << "1. Agregar libro\n"; 
        cout << "2. Buscar un libro por título\n"; 
        cout << "3. Buscar un libro por ISBN\n"; 
        cout << "4. Mostrar todos los libros\n"; 
        cout << "5. Eliminar un libro\n"; 
        cout << "6. Salir\n"; 
        cout << "Seleccione una opción: \n"; 

        // Recibir opcion por el usuario
        cin >> opcion;

        // Validar el valor de opción ingresada por el usuario
        switch (opcion) {
            case opt_agregarLibro:
                agregarLibro(libros, cantidadLibros);
                break;
            case opt_buscarLibroTitulo: 
                buscarLibroPorTitulo(libros, cantidadLibros);
                break;
            case opt_buscarLibroISBN:
                buscarLibroPorISBN(libros, cantidadLibros);
                break;
            case opt_mostrarLibros:
                mostrarLibros(libros, cantidadLibros); 
                break;
            case opt_eliminarLibros:
                eliminarLibros(libros, cantidadLibros); 
                break;
            case opt_salir:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida" << endl;

        }
    } while (opcion != opt_salir);

    return 0;
}