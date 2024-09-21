/*
Archivo que contiene definidos los tipos de excepciones que va a manejar el programa

- FileNotFoundException
- ReadException
- RegexException
*/

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept> // Incluir biblioteca con excepciones estándar
#include <string>

// Declaración de FileNotFoundException: Hereda de std::runtime_error
class FileNotFoundException : public std::runtime_error {
public:
    // Constructor: Indicar el tipo de error que no se pudo abrir el archivo
    explicit FileNotFoundException(const std::string& message)
        : std::runtime_error(message) {}
};

// Declaración de ReadException: Hereda de std::runtime_error
class ReadException : public std::runtime_error {
public:
    // Constructor: Indicar el tipo de error que no se pudo leer
    explicit ReadException(const std::string& message)
        : std::runtime_error(message) {}
};

// Declaración de RegexException: Hereda de std::runtime_error
class RegexException : public std::runtime_error {
public:
    // Constructor: Indicar el tipo de error que no se pudo utilizar la regex
    explicit RegexException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif // EXCEPTIONS_HPP