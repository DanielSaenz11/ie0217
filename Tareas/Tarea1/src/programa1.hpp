/**
 * @file programa1.hpp
 * @brief Archivo que contiene las declaraciones para el programa 1.
 * 
 * @details Este header file contiene la declaración de los enums y structs utilizados para los tipos
 * de conversión. Además, se encuentra la firma de las funciones sobrecargadas para la conversión
 * de unidades de longitud, peso y temperatura.
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

#ifndef PROGRAMA1_HPP
#define PROGRAMA1_HPP

#include <iostream>

/**
 * @enum opciones_menu
 * @brief Contiene las opciones del menu del programa.
 */
enum opciones_menu {
    MENU_LONGITUD = 1,
    MENU_PESO,
    MENU_TEMPERATURA,
    MENU_SALIR
};

/**
 * @enum longitud
 * @brief Contiene los tipos de conversión para las unidades de longitud.
 */
enum longitud {
    METRO,
    KILOMETRO,
    CENTIMETRO,
    MILLA,
    PULGADA
};

/**
 * @enum peso
 * @brief Contiene los tipos de conversión para las unidades de peso.
 */
enum peso {
    GRAMO,
    KILOGRAMO,
    LIBRA,
    ONZA
};

/**
 * @enum temperatura
 * @brief Contiene los tipos de conversión para las unidades de temperatura.
 */
enum temperatura {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
};

/**
 * @struct ConversionLongitud
 * @brief Estructura para almacenar los datos de conversión de longitud.
 * 
 * Esta estructura contiene las unidades de origen y destino para la conversión entre
 * unidades de longitud.
 */
struct ConversionLongitud {
    longitud unidadOrigen;
    longitud unidadDestino;
};

/**
 * @struct ConversionPeso
 * @brief Estructura para almacenar los datos de conversión de peso.
 * 
 * Esta estructura contiene las unidades de origen y destino para la conversión entre
 * unidades de peso.
 */
struct ConversionPeso {
    peso unidadOrigen;
    peso unidadDestino;
};

/**
 * @struct ConversionTemperatura
 * @brief Estructura para almacenar los datos de conversión de temperatura.
 * 
 * Esta estructura contiene las unidades de origen y destino para la conversión entre
 * unidades de temperatura.
 */
struct ConversionTemperatura {
    temperatura unidadOrigen;
    temperatura unidadDestino;
};

/**
 * @brief Convierte unidades de longitud entre sí
 * 
 * Esta función permite realizar la conversión de las unidades de conversión: metro,
 * kilometro, centimetro, milla y pulgada entre sí.
 * 
 * @param conversion Struct de tipo ConversionLongitud
 * @param valor Número al que se quiere realizar la conversión
 * 
 * @return Valor convertido resultante
 */
double convertir(ConversionLongitud conversion, double valor);


/**
 * @brief Convierte unidades de peso entre sí
 * 
 * Esta función permite realizar la conversión de las unidades de conversión: gramo, kilogramo
 * libra y onza entre sí.
 * 
 * @param conversion Struct de tipo ConversionPeso
 * @param valor Número al que se quiere realizar la conversión
 * 
 * @return Valor convertido resultante
 * @overload
 */
double convertir(ConversionPeso conversion, double valor);


/**
 * @brief Convierte unidades de temperatura entre sí
 * 
 * Esta función permite realizar la conversión de las unidades de conversión: Celsius, Fahrenheit
 * y Kelvin entre sí.
 * 
 * @param conversion Struct de tipo ConversionTemperatura
 * @param valor Número al que se quiere realizar la conversión
 * 
 * @return Valor convertido resultante
 * @overload
 */
double convertir(ConversionTemperatura conversion, double valor);

/**
 * @brief Muestra el menú del programa recursivamente.
 * 
 * Esta función se encarga de mostrar de forma recursiva el menú del programa.
 * Se llama dentro de la función main() hasta que se indique la opción de salir.
 * 
 * @return void
 */
void mostrarMenu();

#endif // PROGRAMA1_HPP