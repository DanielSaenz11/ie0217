/**
 * Programa que imprime el numero de argumentos recibidos para main (argc)
 * y el nombre del programa (argv[0])
 */


#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "argc: " << argc << std::endl;
    std::cout << "argv: " << argv[0] << std::endl;

    return 0;
}    