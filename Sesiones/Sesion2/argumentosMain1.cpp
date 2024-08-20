/**
 * Argumentos de la funcion main
 * 
 * argc: Argument count
 * argv: Argument vector
 * 
 * Para recibir argumentos desde la linea de comandos
 */
#include <iostream>

int main(int argc, char* argv[]) {
    // Imprime argc y argv[0]
    std::cout << "Numero de argumentos: " << argc << std::endl;
    std::cout << "Nombre del programa: " << argv[0] << std::endl;

    // Imprimir argumentos adicionales si existen
    if (argc > 1) {
        std::cout << "Argumentos adicionales:" << std::endl;

        for (int i = 1; i < argc; ++i) {
            std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
        }
    }

    return 0;
}