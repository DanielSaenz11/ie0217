/**
 * Ejemplos de declaración de iteradores de tipo:
 * - vector<int>
 * - map<char, int>
 * 
 * begin() apunta al primer elemento
 * end() apunta un espacio más allá del último elemento (para indicar que se terminó)
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Funcion main(): Punto de entrada del programa
int main() {
    // Declaración de vector de tipo integer
    vector<int> num {1, 2, 3};

    // Declaración de iterador sobre vector
    vector<int>::iterator vec_itr;

    // Error: itr sólo se puede usar con integer
    // vector<double>::iterator itr = num.begin()

    // Declaración de iterador sobre mapa
    map<char, int>::iterator map_itr;

    return 0;

}