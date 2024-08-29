/**
 * @file programa2.hpp
 * @brief Archivo que contiene las declaraciones para el programa 2.
 * 
 * @details Este header file contiene la declaración del enum para los casos del menú, así como la
 * firma de las funciones que se utilizan para calcular las estadísticas del arreglo solicitado.
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

#ifndef PROGRAMA2_HPP
#define PROGRAMA2_HPP

#include <iostream>

/**
 * @enum casos_menu
 * @brief Describe las opciones para escoger dentro del menú del programa.
 */
enum casos_menu {
    MOSTRAR_ESTADISTICAS = 1,
    BUSCAR_NUMERO,
    SALIR_PROGRAMA
};

/**
 * @brief Calcula la suma de todos los números de un arreglo.
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
 * @brief Calcula el promedio de los números dentro de un arreglo.
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
 * @brief Busca el número máximo en un arreglo.
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
 * @brief Busca el número mínimo en un arreglo.
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
 * @brief Busca un número solicitado dentro de la función en un arreglo.
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