/*
Archivo que contiene la implementación de la clase FileReader
Esta contiene un class template para permitir recibir cualquier tipo de Container
*/

#ifndef FILEREADER_HPP
#define FILEREADER_HPP

// Incluir bibliotecas utilizadas
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Exceptions.hpp" // Incluir header file con la implementación de las excepciones

// Class template
template <typename Container>
class FileReader {
public:
    // Constructor de la clase FileReader: Recibe la ruta del archivo
    FileReader(const std::string& filePath) : filePath(filePath) {}

    // Función miembro para leer el archivo: Agrega cada línea al final del Container especificado
    void readFile(Container& container) {

        std::ifstream file(filePath);

        // Si no se pudo abrir el archivo, se lanza la excepción con el mensaje indicado y el path
        if (!file.is_open()) {
            throw FileNotFoundException("Error: No se pudo abrir el archivo " + filePath);
        }

        std::string line; // Línea leída
        // Recorrer el file
        while (std::getline(file, line)) {
            container.push_back(line); // Agregar al final del container el contenido de la línea
        }

        file.close(); // Cerrar el archivo
    }

private:
    std::string filePath; // Atributo privado que contiene la ruta del archivo
};

#endif // FILEREADER_HPP
