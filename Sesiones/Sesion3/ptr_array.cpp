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
    float arr[3];

    // Declarar puntero tipo float
    float *ptr;

    cout << "Displaying address using arrays: " << endl;

    // Mostrar la direccion de cada entrada del arreglo
    for (int i = 0; i < 3; ++i) {
        cout << "&arr[" << i << "] = " << &arr[i] << endl;
    }

    // ptr = &arr[0]
    ptr = arr; // Asignar la direccion del primer elemento de arr a ptr

    cout << "Displaying address using pointers: " << endl;

    // Mostrar la direccion de cada entrada con punteros
    for (int i = 0; i < 3; ++i) {
        cout << "ptr + " << i << " = " << ptr + i << endl;
    }

    return 0;
}