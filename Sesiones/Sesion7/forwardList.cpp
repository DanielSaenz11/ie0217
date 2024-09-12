/**
 * Tipos de iteradores: forward iterator
 * 
 * Pueden leer/escribir valores mientras iteran hacia adelante
 * Se utiliza ++ sobre el iterador para avanzar y utilizar * y ->
 * para leer o acceder a miembros
 */

#include <iostream>
#include <forward_list> // forward_list

using namespace std;

// Función main(): Punto de entrada en la ejecución del programa
int main() {
    // Declaración de forward_list de tipo integer
    forward_list<int> nums {1, 2, 3, 4};

    // Inicializar iterador que apunta al inicio de la forward_list
    forward_list<int>::iterator itr = nums.before_begin();

    // Recorrido del forward_list hasta llegar al final
    while (itr != nums.end()) {
        // Desreferenciar valor del itr
        int original_value = *itr;

        // Duplicar el valor usando la desreferencia del iterador itr
        *itr = original_value * 2;

        itr++;
    }

    // Recorrido de forward list para imprimir valores
    for (int num: nums) {
        cout << num << ", ";
    }
    cout << endl; // Salto de línea al final

    return 0;
}