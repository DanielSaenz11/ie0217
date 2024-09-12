/**
 * Iteradores de acceso aleatorio
 * 
 * Tienen todas las propiedades de los iteradores bidireccionales junto con
 * acceso aleatorio.
 * Permite el uso de * y [] para acceder a los elementos en ciertas posiciones
 * 
 * Ejemplo: Vector, deque, array
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Crear vector con elementos de tipo entero
    vector<int> vec {1, 2, 3, 4};

    // Crear iteradores que apunten al primer y último elemento
    vector<int>::iterator itr_first = vec.begin();

    // Se disminuye en 1 pues last() apunta uno después
    vector<int>::iterator itr_last = vec.end() - 1;

    // Mostrar elementos del vector del comienzo
    cout << "First Element: " << *itr_first << endl; // Acceso con *
    cout << "Second Element: " << itr_first[1] << endl; // Acceso con []

    // Mostrar elementos del final
    cout << "Second Last Element: " << *(itr_last - 1) << endl;
    cout << "Last Element: " << *(itr_last) << endl;

    return 0;
}