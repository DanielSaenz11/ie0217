
#include "programa2.hpp"

using namespace std;

int calcularSuma(int* arr, int largo) {
    int sumaTotal = 0; // Variable que guarda la suma total del arreglo

    // Recorrido del arreglo
    for (int i = 0; i < largo; i++) {
        sumaTotal += *(arr + i); // Sumar cada indice del arreglo por medio del puntero arr
    }

    return sumaTotal; // Retornar sumaTotal
}

double calcularPromedio(int* arr, int largo) {

    /* 
    El promedio consiste en la suma total entre la cantidad de elementos
    Se llama calcularSuma() y se divide entre el largo
     */
    double promedio = (double)calcularSuma(arr, largo) / largo;

    return promedio; // Retornar promedio calculado
}

int calcularMaximo(int* arr, int largo) {
    
    // Se coloca inicialmente el numero maximo como el primer elemento del arreglo
    int numMax = *arr;
    
    // Recorrido del arreglo desde el segundo elemento al final
    for (int i = 1; i < largo; i++) {
        // Si se encuentra un numero mayor, se cambia el valor de numMax
        if (numMax < *(arr + i)) {
            numMax = *(arr + i);
        }
    }

    return numMax; // Se retorna el numero maximo del array
}

int calcularMinimo(int* arr, int largo) {
    
    // Se coloca inicialmente el numero maximo como el primer elemento del arreglo
    int numMin = *arr;
    
    // Recorrido del arreglo desde el segundo elemento al final
    for (int i = 1; i < largo; i++) {
        // Si se encuentra un numero menor, se cambia el valor de numMin
        if (numMin > *(arr + i)) {
            numMin = *(arr + i);
        }
    }
    
    return numMin; // Se retorna el numero minimo del arreglo
}

void buscarNumero(int* arr, int largo) {

    // Declaracion de numero a buscar
    int numBusqueda;
    
    // Ingreso del usuario del numero a buscar
    cout << "Ingrese el número para buscar en el arreglo: ";
    cin >> numBusqueda;

    // Recorrido del arreglo
    for (int i = 0; i < largo; i++) {
        // Verificar si hubo coincidencia entre el numero a buscar y uno en el arreglo
        if (numBusqueda == *(arr + i)) {
            // Mostrar mensaje con detalles del numero encontrado
            cout << "Se encontró el número " << numBusqueda << " en el índice "
            << i << " del arreglo." << endl;
            return; // Salir de la funcion
        }
    }
    // En el caso que no se encontro una coincidencia
    cout << "No se encontró el número " << numBusqueda << " en el arreglo." << endl;
    
}