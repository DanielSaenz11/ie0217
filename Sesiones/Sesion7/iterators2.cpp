/**
 * Iteradores para vector
 * 
 * El vector contiene elementos de tipo string
 * Se itera desde begin() hasta end()
 * En cada repetición se aumenta el valor del iterador en 1
 */

#include <iostream>
#include <vector> // container vector

using namespace std;

// Funcion main(): Punto de entrada de ejecución del programa
int main() {
    // Inicializar vector languages con elemento tipo string
    vector<string> languages = {"Python", "C++", "Java"};
    
    // Declaración de iterador de tipo string
    vector<string>::iterator itr;

    // Iterar sobre todos los elementos -> Desde begin() hasta que sea distinto de end()
    for (itr = languages.begin(); itr != languages.end(); itr++) {
        cout << *itr << ", "; // Desreferenciar iterador para acceder a su valor
    }

    // Asignación de tipo automáticamente
    // auto itr = languages.begin();

    return 0;
}