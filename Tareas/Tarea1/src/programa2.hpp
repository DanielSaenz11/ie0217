#ifndef PROGRAMA2_HPP
#define PROGRAMA2_HPP

#include <iostream>

enum CASOS_MENU {
    MostrarEstadisticas = 1,
    BuscarNumero,
    SalirPrograma
};

/**
 * @brief Calcula la suma de todos los números de un arreglo
 * 
 * Esta función permita calcular la suma de todos los números enteros almacenados
 * en un arreglo. Recibe un puntero al primer elemento y el largo de este.
 * 
 * @param arr    Puntero entero que apunta al primer elemento del array
 * @param largo  Entero que indica el largo del array
 * 
 * @return       Resultado de suma total
 */
int calcularSuma(int* arr, int largo);

/**
 * @brief Calcula el promedio de los números dentro de un arreglo
 * 
 * Esta función permite calcular el promedio o media aritmética de los números
 * enteros en un arreglo. Recibe un puntero al primer elemento y el largo de este.
 * 
 * @param arr    Puntero entero que apunta al primer elemento del array
 * @param largo  Entero que indica el largo del array
 * 
 * @return       Resultado del promedio final
 */
double calcularPromedio(int* arr, int largo);

/**
 * @brief Busca el número máximo en un arreglo
 * 
 * Esta función determina el número máximo en un arreglo de números enteros. Recibe
 * un puntero al primer elemento y el largo de este.
 * 
 * @param arr    Puntero entero que apunta al primer elemento del array
 * @param largo  Entero que indica el largo del array
 * 
 * @return       Número máximo encontrado
 */
int calcularMaximo(int* arr, int largo);


/**
 * @brief Busca el número mínimo en un arreglo
 * 
 * Esta función determina el número mínimo en un arreglo de números enteros. Recibe
 * un puntero al primer elemento y el largo de este.
 * 
 * @param arr    Puntero entero que apunta al primer elemento del array
 * @param largo  Entero que indica el largo del array
 * 
 * @return       Número mínimo encontrado
 */
int calcularMinimo(int* arr, int largo);

/**
 * @brief Busca un número solicitado dentro de la función en un arreglo
 * 
 * Esta función se encarga de solicitarle al usuario que ingrese un número entero
 * para buscarlo en un arreglo. Si lo encuentra, muestra un mensaje positivo; en el caso
 * contrario, muestra uno negativo. 
 * 
 * @param arr    Puntero entero que apunta al primer elemento del array
 * @param largo  Entero que indica el largo del array
 * 
 * @return       void
 */
void buscarNumero(int* arr, int largo);

#endif // PROGRAMA2_HPP