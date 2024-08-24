
// Incluir librerias necesarias
#include <iostream> // Input/Output
#include <cstring> // Comparaciones de strings
#include "funciones.hpp" // Header file definido

using namespace std;

/**
 * @brief Agrega un nuevo libro a la colección.
 *
 * Esta función permite al usuario ingresar los detalles de un nuevo libro
 * (título, autor, ISBN y año de publicación) y lo almacena en el array de libros.
 *
 * @param libros            Array de estructuras Libro donde se almacenan los libros.
 * @param cantidadLibros    Referencia a un entero que indica la cantidad actual de libros en la colección.
 *                          Este valor se incrementará en uno después de agregar un nuevo libro.
 *
 * @return void
 */
void agregarLibro(Libro libros[], int &cantidadLibros) {
    // Ingreso de los datos del libro
    cout << "Ingrese el título del libro: ";
    cin.ignore(); // Limpiar el buffer de entrada
    cin.getline(libros[cantidadLibros].titulo, 100); // Por si contiene espacios

    cout << "Ingrese el autor del libro: ";
    cin.getline(libros[cantidadLibros].autor, 100); // Por si contiene espacios

    cout << "Ingrese el ISBN del libro: ";
    cin.getline(libros[cantidadLibros].ISBN, 13); // Por si contiene espacios
    
    cout << "Ingrese el año de publicación del libro: ";
    cin >> libros[cantidadLibros].anioPublicacion; // Por si contiene espacios

    // Se recibe la referencia, entonces sí se modifica el valor fuera de la funcion
    cantidadLibros++;
}

/**
 * @brief Mostrar todos los libros almacenados en el arreglo
 * @param libro Arreglo de libros almacenados
 * @param cantidadLibros Numero entero que contiene la cantidad de libros almacenados
 */
void mostrarLibros(Libro libros[], int cantidadLibros) {
    // En el caso en que no hay libros para mostrar
    if (0 == cantidadLibros) {
        cout << "No hay libros en la lista" << endl;
    }
    else {
        // Recorrer el arreglo de libros
        for (int i = 0; i < cantidadLibros; i++) {
            // Mostrar informacion del libro
            cout << i + 1 << ". " << libros[i].titulo << " por " << libros[i].autor
            << " (ISBN: " << libros[i].ISBN << ", Año: " << libros[i].anioPublicacion << ")"
            << endl;
        }
    }
}

/**
 * @brief Búsqueda de libro por ingreso del titulo en el arreglo
 * @param libro Arreglo de libros almacenados
 * @param cantidadLibros Numero entero que contiene la cantidad de libros almacenados
 */
void buscarLibroPorTitulo(Libro libros[], int cantidadLibros) {
    // Ingreso del titulo del libro a buscar
    char titulo[100];
    cout << "Ingrese el titulo del libro que desea buscar: ";
    cin.ignore();
    cin.getline(titulo, 100);

    // Declaracion de condicion de encontrado de libro para la búsqueda
    bool encontrado = false;

    // Recorrer todos los libros almacenados en el arreglo
    for (int i=0; i < cantidadLibros; i++) {

        // Si strcpm() retorna 0, ambos strings son iguales
        if (strcmp(libros[i].titulo, titulo) == 0) {
            // Mostrar información
            cout << "Libro encontrado: " << libros[i].titulo << " por " << libros[i].autor << endl;
            
            encontrado = true; // Cambiar el valor del booleano a true
            break; // Salir del loop
        }
    }

    // Mostrar mensaje si no se encontró el libro
    if (!encontrado) {
        cout << "Libro no ha sido encontrado." << endl;
    }
}

/**
 * @brief Búsqueda de libro por ingreso del ISBN en el arreglo
 * @param libro Arreglo de libros almacenados
 * @param cantidadLibros Numero entero que contiene la cantidad de libros almacenados
 */
void buscarLibroPorISBN(Libro libros[], int cantidadLibros) {
    // Ingreso del ISBN que desea buscar
    char ISBN[13];
    cout << "Ingrese el ISBN del libro que desea buscar: ";
    cin.ignore();
    cin.getline(ISBN, 13);

    // Booleano que determina la condicion de busqueda
    bool encontrado = false;

    // Recorrer el arreglo de datos
    for (int i = 0; i < cantidadLibros; i++) {

        // Si strcpm() retorna 0, ambos strings son iguales
        if (strcmp(libros[i].ISBN, ISBN) == 0) {
            // Mostrar información
            cout << "Libro encontrado: " << libros[i].titulo << " por " << libros[i].autor << endl;
            
            encontrado = true; // Cambiar el valor del booleano a true
            break; // Salir del loop
        }
    }

    // Mostrar mensaje si no se encontró el libro
    if (!encontrado) {
        cout << "Libro no encontrado." << endl;
    }
}

/**
 * @brief Eliminar un libro en el arreglo al buscar por ISBN
 * @param libro Arreglo de libros almacenados
 * @param cantidadLibros Numero entero que contiene la cantidad de libros almacenados
 */
void eliminarLibros(Libro libros[], int &cantidadLibros) {

    // Ingreso del ISBN del libro para eliminarlo
    char ISBN[13];
    cout << "Ingrese el ISBN del libro que desea eliminar: ";
    cin.ignore();
    cin.getline(ISBN, 13);

    // Recorrido del arreglo de libros
    for (int i = 0; i < cantidadLibros; i++) {

        // Si strcpm() retorna 0, ambos strings son iguales
        if (strcmp(libros[i].ISBN, ISBN) == 0) {
            
            // Mover todas las entradas una posición a la izquierda
            for (int j = i; j < cantidadLibros-1; j++) {
                libros[j] = libros[j + 1];
            }

            cantidadLibros--; // Disminuir la cantidad de libros
            cout << "Libro eliminado." << endl;
            return; // Salir de la funcion
        }
    }

    // Mostrar mensaje si no hubo coincidencia de ISBN
    cout << "Libro no encontrado." << endl;
}


