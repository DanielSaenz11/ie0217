#include <iostream>
using namespace std;

int main() {
    int* arr = new int[5];  // Asigna un arreglo de 5 enteros

    // Inicializa el arreglo
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    cout << "Valor fuera de límites: " << arr[10] << endl;

    delete[] arr;  // Libera la memoria asignada
    return 0;
}

// g++ -g -fsanitize=address -o out_of_bounds out_of_bounds.cpp
// ./out_of_bounds
