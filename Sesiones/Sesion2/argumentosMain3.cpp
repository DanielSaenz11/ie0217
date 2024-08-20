/**
 * Programa que imprime el numero de argumentos recibidos para main (argc),
 * el nombre del ejecutable y 3 argumentos de la linea de comando
 * 
 * Es necesario colocar al menos 3 argumentos aparte del nombre, en caso contrario
 * se genera un error
 * 
 * Se puede solucionar con un for que recorra el rango de [1, argc[
 */

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "argc: " << argc << std::endl;
    std::cout << "argv[0]: " << argv[0] << std::endl; // Nombre del programa
    std::cout << "argv[1]: " << argv[1] << std::endl;
    std::cout << "argv[2]: " << argv[2] << std::endl;
    std::cout << "argv[3]: " << argv[3] << std::endl;

    return 0;
}    