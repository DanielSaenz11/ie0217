#include <iostream>
using namespace std;

int main() {
    int* arr = new int[10];  // Asignación dinámica de memoria para un arreglo de 10 enteros

    // Inicialización del arreglo
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }

    // Mostrar los valores del arreglo
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Se libera la memoria asignada para arr

    return 0;
}

