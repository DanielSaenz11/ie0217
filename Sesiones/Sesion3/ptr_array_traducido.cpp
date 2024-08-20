/**
 * Uso de punteros con arreglos de datos
 * 
 * ptr = &arr[0];
 * ptr = arr;
 * 
 * ptr + n es igual a &arr[n]
 * *(ptr + n) es igual a arr[n]
 */

#include <iostream>
using namespace std;

int main() {
    float arreglo[3];

    // Declarar puntero tipo float
    float *puntero;

    cout << "Displaying address using arrays: " << endl;

    // Mostrar la direccion de cada entrada del arreglo
    for (int i = 0; i < 3; ++i) {
        cout << "&arreglo[" << i << "] = " << &arreglo[i] << endl;
    }

    // puntero = &arreglo[0]
    puntero = arreglo; // Asignar la direccion del primer elemento de arreglo a puntero

    cout << "Displaying address using pointers: " << endl;

    // Mostrar la direccion de cada entrada con punteros
    for (int i = 0; i < 3; ++i) {
        cout << "puntero + " << i << " = " << puntero + i << endl;
    }

    return 0;
}