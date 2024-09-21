/*
Archivo que contiene la implementación de las siguientes utilidades de regex:

1) regexSearch()
2) regexReplace()
*/

#ifndef REGEXUTILS_HPP
#define REGEXUTILS_HPP

#include <regex> // Utilizar expresiones regulares
#include <string>
#include <vector>
#include <stdexcept>
#include "Exceptions.hpp" // Biblioteca con declaración de excepciones para el programa

// Implementación de la función regexSearch(): Retorna un vector con las líneas con coincidencias
std::vector<std::string> regexSearch(const std::vector<std::string>& lines, const std::string& pattern) {
    std::vector<std::string> matches; // Vector con las líneas con coincidencias
    std::regex regexPattern; // Expresión regular para buscar

    // try-except clause
    try {
        // Patrón a regex
        regexPattern = std::regex(pattern);
    } catch (const std::regex_error&) {
        // Lanzar excepción con mensaje indicado
        throw RegexException("Error: Patrón de expresión regular inválido.");
    }

    // Recorrer con todas las líneas
    for (const auto& line : lines) {
        // Si hubo coincidencia en la línea con el método nativo de regex
        if (std::regex_search(line, regexPattern)) {
            matches.push_back(line); // Agregar línea con match al final del contenedor
        }
    }

    return matches; // Retornar vector con las líneas coincidentes
}

// Implementación de la función regexReplace(): Modifica las líneas con la expresión regular de intéres por un string de reemplazo
void regexReplace(std::vector<std::string>& lines, const std::string& pattern, const std::string& replacement) {
    std::regex regexPattern; // Patrón regex para buscar

    // try-except clause
    try {
        regexPattern = std::regex(pattern); // Convertir a regex
    } catch (const std::regex_error&) {
        // Si hubo un error al convertir a regex, se lanza la excepción con el mensaje indicado
        throw RegexException("Error: Patrón de expresión regular inválido.");
    }

    // Recorrer todas las líneas del archivo
    for (auto& line : lines) {
        line = std::regex_replace(line, regexPattern, replacement); // Reemplazar el pattern con el replacement ingresado en la línea
    }
}

#endif // REGEXUTILS_HPP
