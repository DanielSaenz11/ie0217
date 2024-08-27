#include <iostream>
#include "programa2.hpp"

using namespace std;

int calcularSuma(int* arr, int largo) {
    int sumaTotal = 0;

    for (int i = 0; i < largo; i++) {
        sumaTotal += *(arr + i);
    }

    return sumaTotal;
}

double calcularPromedio(int* arr, int largo) {

    double promedio = (double)calcularSuma(arr, largo) / largo;

    return promedio;
}

int calcularMaximo(int* arr, int largo) {
    int numMax = *arr;
    
    for (int i = 1; i < largo; i++) {
        if (numMax < *(arr + i)) {
            numMax = *(arr + i);
        }
    }

    return numMax;
}

int calcularMinimo(int* arr, int largo) {
    int numMin = *arr;
    
    for (int i = 1; i < largo; i++) {
        if (numMin > *(arr + i)) {
            numMin = *(arr + i);
        }
    }

    return numMin;
}

void buscarNumero(int* arr, int largo) {
    int numBusqueda;
    
    cout << "Ingrese el número para buscar en el arreglo: ";
    cin >> numBusqueda;

    for (int i = 0; i < largo; i++) {
        if (numBusqueda == i) {
            cout << "Se encontró el número " << numBusqueda << " en el índice "
            << i << " del arreglo." << endl;
            return;
        }
    }

    cout << "No se encontró el número " << numBusqueda << " en el arreglo." << endl;
    
}