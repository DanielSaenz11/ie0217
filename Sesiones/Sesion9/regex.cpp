/*
Regular Expressions (regex)

Patrones utilizados para buscar y manipular cadenas de texto

Función utilizada: std::regex_search(string, regex)
Retorna un booleano para indicar el estado de búsqueda del regex dentro del string
*/

#include <iostream>
#include <regex> // Biblioteca para manejar expresiones regulares

// Función main(): Punto de entrada de ejecución del programa
int main() {
    // Expresión regular: Coincide con "my regex" y "your regex"
    auto const regex = std::regex("(my|your) regex");

    // Primera comparación: Coincidencia con "my regex"
    auto const myText = std::string("A piece of text that contains my regex.");
    bool const myTextContainsRegex = std::regex_search(myText, regex);

    // Segunda comparación: Coincidencia con "your regex"
    auto const yourText = std::string("A piece of text that contains your regex.");
    bool const yourTextContainsRegex = std::regex_search(yourText, regex);

    // Tercera comparación: No hay coincidencia
    auto const theirText = std::string("A piece of text that contains their regex.");
    bool const theirTextContainsRegex = std::regex_search(theirText, regex);

    // Imprimir resultados booleanos para cada comparación en orden
    std::cout << std::boolalpha
              << myTextContainsRegex << "\n"
              << yourTextContainsRegex << "\n"
              << theirTextContainsRegex << "\n";

    return 0;         
}