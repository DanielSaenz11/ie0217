/*
Archivo con la función main(): Punto de entrada de ejecución del programa

Crea un objeto biblioteca, agrega dos libros y muestra el contenido de la biblioteca
*/

#include "biblioteca.hpp" // Incluir header file con la declaración de la clase Biblioteca

// Función main()
int main() {
    Biblioteca biblioteca; // Crear objeto de clase Biblioteca

    // Agregar dos libros a la biblioteca
    biblioteca.agregarLibro("El Gran Gatsby", "F. Scott Fitzgerald");
    biblioteca.agregarLibro("1984", "George Orwell");

    // Mostrar el contenido de la biblioteca
    biblioteca.mostrarCatalogo();

    return 0;
}