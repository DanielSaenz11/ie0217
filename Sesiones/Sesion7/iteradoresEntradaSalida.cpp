/**
 * Iteradores de entrada:
 * Leer valores mientras iteran hacia delante.
 * Ejemplo: Iterador del flujo de entrada
 * 
 * Iteradores de salida:
 * Escribir valores mientras iteran hacia delante.
 * Operador = para escribir valores
 */

#include <iostream>
// #include <>

using namespace std;

// Función main(): Punto de entrada de ejecución del programa
int main() {
    
    // Declaración de un iterador de entrada para leer valores del cin
    istream_iterator<int> input_itr(cin);

    // Declaración de un iterador de salida para escribir enteros en la consola
    ostream_iterator<int> output_itr(cout, " ");

    return 0;
}