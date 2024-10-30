#include <iostream>
using namespace std;

int main() {
    int* arr = new int[5];  // Asigna un arreglo de 5 enteros

    // Inicializa el arreglo
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    // Se accede a un valor fuera de los límites del arreglo (el índice máximo es 4)
    // Se arregló al acceder a un valor que sí está dentro de los límites del arreglo
    cout << "Valor dentro de límites: " << arr[4] << endl;

    delete[] arr;  // Libera la memoria asignada
    return 0;
}

