/**
 * @file programa2.cpp
 * @brief Archivo que contiene las implementaciones para el programa 2.
 * 
 * @details Este archivo contiene la definición de las funciones para calcular las estadísticas del arreglo
 * ingresado: suma total, promedio, valor máximo y valor mínimo. Además, posee la definición de la
 * búsqueda de un número en el arreglo ingresado.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 30/08/2024
 */

#include "programa2.hpp"

using namespace std;

int calcularSuma(int *pArr, int largo) {
    int sumaTotal = 0; // Variable que guarda la suma total del arreglo

    // Recorrido del arreglo
    for (int i = 0; i < largo; i++) {
        sumaTotal += *(pArr + i); // Sumar cada indice del arreglo por medio del puntero pArr
    }

    return sumaTotal; // Retornar sumaTotal
}

double calcularPromedio(int *pArr, int largo) {

    /* 
    El promedio consiste en la suma total entre la cantidad de elementos
    Se llama calcularSuma() y se divide entre el largo
     */
    double promedio = static_cast<double>((pArr, largo)) / largo;

    return promedio; // Retornar promedio calculado
}

int calcularMaximo(int *pArr, int largo) {
    
    // Se coloca inicialmente el numero maximo como el primer elemento del arreglo
    int numMax = *pArr;
    
    // Recorrido del arreglo desde el segundo elemento al final
    for (int i = 1; i < largo; i++) {
        // Si se encuentra un numero mayor, se cambia el valor de numMax
        if (numMax < *(pArr + i)) {
            numMax = *(pArr + i);
        }
    }

    return numMax; // Se retorna el numero maximo del array
}

int calcularMinimo(int *pArr, int largo) {
    
    // Se coloca inicialmente el numero maximo como el primer elemento del arreglo
    int numMin = *pArr;
    
    // Recorrido del arreglo desde el segundo elemento al final
    for (int i = 1; i < largo; i++) {
        // Si se encuentra un numero menor, se cambia el valor de numMin
        if (numMin > *(pArr + i)) {
            numMin = *(pArr + i);
        }
    }
    
    return numMin; // Se retorna el numero minimo del arreglo
}

void buscarNumero(int *pArr, int largo) {

    // Declaracion de numero a buscar
    int numBusqueda;
    
    // Ingreso del usuario del numero a buscar
    cout << "Ingrese el número para buscar en el arreglo: ";
    cin >> numBusqueda;

    // Recorrido del arreglo
    for (int i = 0; i < largo; i++) {
        // Verificar si hubo coincidencia entre el numero a buscar y uno en el arreglo
        if (numBusqueda == *(pArr + i)) {
            // Mostrar mensaje con detalles del numero encontrado
            cout << "Se encontró el número " << numBusqueda << " en el índice "
            << i << " del arreglo." << endl;
            return; // Salir de la funcion
        }
    }
    // En el caso que no se encontro una coincidencia
    cout << "No se encontró el número " << numBusqueda << " en el arreglo." << endl;
    
}
