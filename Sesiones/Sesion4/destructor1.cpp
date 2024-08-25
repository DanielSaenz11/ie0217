/**
 * Codigo de la presentacion:
 * Programa que trata sobre el destructor de una clase (limpiar)
 * 
 * ~nombreClase() {
 *     // Codigo
 * }
 */

#include <iostream>
#include <fstream>

class Archivo {
    // Miembros privados
    private:
        std::fstream archivo; // Tipo de file

    public:
        // Constructor de la clase
        Archivo(std::string nombre_archivo) {

            // Abrir el archivo con el nombre ingresado en el constructor
            archivo.open(nombre_archivo, std::ios::in | std::ios::out | std::ios::app);
            
            // Mensaej si no se pudo abrir el file
            if (!archivo.is_open()) {
                std::cout << "No se pudo abrir el archivo " << nombre_archivo << std::endl;
            }
        }

        ~Archivo() {

            // Si se pudo abrir en el constructor, se cierra
            if (archivo.is_open()) {
                archivo.close();
            }
        }

};

int main() {

    // Inicializar una instancia de la clase Archivo
    Archivo mi_archivo("datos.txt");

    // hacer algo con el archivo
    
    // Se ejecuta el destructor cuando termina la ejecucion de la funcion main()

    return 0;
}