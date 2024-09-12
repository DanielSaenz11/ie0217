/**
 * Ejemplo de sorting con algoritmos de STL
 * 
 * - Con operador regular <
 * - Por medio de una función
 * - Por medio de un objeto
 */

#include <iostream> // std::cout
#include <algorithm> // std::sort
#include <vector> // std::vector

// Función para ordenar con este criterio
bool myfunction(int i, int j) {
    return (i<j);
}

// Struct para hacer sorting con el criterio en bool operator()
struct myclass {
    bool operator() (int i, int j) {
        return (i<j);
    }
} myobject; // Objeto de tipo myclass

// Función main(): Punto de entrada de ejecución del programa
int main() {
    // Declaración de arreglo de enteros
    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};

    // Coloca valores del arreglo en un vector
    std::vector<int> myvector (myints, myints+8);

    // Utilizando comparación predeterminada (<)
    std::sort (myvector.begin(), myvector.begin()+4); // Ordena los primeros 4 elementos

    // Utilizando función como comparación
    std::sort (myvector.begin() + 4, myvector.end(), myfunction); // Ordena del quinto elemento al final

    // Utilizando objeto como comparación
    std::sort (myvector.begin(), myvector.end(), myobject); // Ordena todo el vector

    // Imprimir el contenido del vector
    std::cout << "myvector contains:";

    // Recorrer el vector con iteradores
    for (std::vector<int>::iterator it=myvector.begin(); it != myvector.end(); it++) {
        std::cout << " " << *it;
    }
    std::cout << "\n";

    return 0;
}