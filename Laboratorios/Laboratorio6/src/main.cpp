/*
main.cpp

Programa que contiene a la función main() y corresponde al punto de entrada de ejecución

1) Se revisa la entrada de argumentos por la línea de comandos
2) Lee el archivo línea por línea
3) Procesa el texto de las líneas
4) Busca líneas con números
5) Cambia líneas con números por etiquetas

*/
#include <iostream>
#include "FileReader.hpp"
#include "TextProcessor.hpp"
#include "RegexUtils.hpp"
#include "Exceptions.hpp"

int main(int argc, char* argv[]) {

    // Verificar la entrada de 2 argumentos de la línea de comandos (nombre + ruta_archivo)
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <archivo_texto>" << std::endl; // Imprimir instrucciones de ejecución del programa
        return 1; // Retornar estado de error
    }

    std::string filePath = argv[1]; // Ruta al archivo corresponde al argumento en el índice 1 del argv
    std::vector<std::string> lines; // Vector que guarda las líneas del archivo

    // try-except clause
    try {
        // Declaración de objeto FileReader con contenedor vector<std::string>
        FileReader<std::vector<std::string>> fileReader(filePath);
        fileReader.readFile(lines); // Leer líneas del archivo y las coloca en el container designado en la declaración del objeto
        
        // Mensaje para indicar la exitosa lectura del archivo y el total de líneas
        std::cout << "Archivo leído correctamente. Total de líneas: " << lines.size() << std::endl;

        // Procesar el texto utilizando una lambda que cuenta las líneas
        int lineCount = 0; // Contador de líneas procesadas

        // Function template processText para contar líneas no vacías: Recibe el container de lines y la función anónima
        processText(lines, [&](const std::string& line) {
            // Se ejecuta mientras la línea no esté vacía
            if (!line.empty()) {
                lineCount++; // Aumenta el contador de líneas procesadas
            }
        });

        // Imprimir cantidad de líneas no vacías
        std::cout << "Líneas no vacías: " << lineCount << std::endl;

        // Buscar un patrón con expresiones regulares
        std::string pattern = "\\d+";  // Busca cualquier número en las líneas
        std::vector<std::string> matchedLines = regexSearch(lines, pattern); // Busca las líneas que hubo coincidencia con el patrón dentro de lines
        std::cout << "Líneas que contienen números: " << matchedLines.size() << std::endl; // Cantidad de líneas con números

        // Reemplazar los números con una etiqueta
        regexReplace(lines, pattern, "[Número]");
        std::cout << "Números reemplazados en las líneas." << std::endl;

    } catch (const FileNotFoundException& e) {
        // Error si no se encontró el file ingresado
        std::cerr << e.what() << std::endl;
        return 1; // Retornar estado de error
    } catch (const RegexException& e) {
        // Error al utilizar la expresión regular
        std::cerr << e.what() << std::endl;
        return 1; // Retornar estado de error
    }

    return 0;
}