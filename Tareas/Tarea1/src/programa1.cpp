/**
 * @file programa1.cpp
 * @brief Archivo que contiene las implementaciones de las funciones para el programa 1.
 * 
 * @details Este archivo .cpp contiene el desarrollo de las funciones para realizar las conversiones
 * entre las unidades de longitud, peso y temperatura. Para cada tipo de conversión, se estableció
 * una función sobrecargada, en ese orden.
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

#include "programa1.hpp"

using namespace std;

/**
 * @brief Array de enteros constantes que almacena los factores de conversión para unidades
 * de longitud.
 * 
 * Para identificar cuál factor corresponde a cuál unidad, se utiliza el enum longitud
 */
const double FACTORES_LONGITUD[] = {1.0, 1000.0, 0.01, 1609.34, 0.0254};

/**
 * @brief Array de enteros constantes que almacena los factores de conversión para unidades
 * de peso.
 * 
 * Para identificar cuál factor corresponde a cuál unidad, se utiliza el enum peso
 */
const double FACTORES_PESO[] = {1.0, 1000.0, 453.592, 28.3495};


double convertir(ConversionLongitud conversion, double valor) {

    // Pasar unidad de origen a metros (definida como unidad base)
    double resultado = valor * FACTORES_LONGITUD[static_cast<int>(conversion.unidadOrigen)];

    // Pasar de metros a unidad de destino
    resultado /= FACTORES_LONGITUD[static_cast<int>(conversion.unidadDestino)];

    return resultado;
}

double convertir(ConversionPeso conversion, double valor) {

    // Pasar unidad de origen a gramos (definida como unidad base)
    double resultado = valor * FACTORES_PESO[static_cast<int>(conversion.unidadOrigen)];

    // Pasar de gramos a unidad de destino
    resultado /= FACTORES_PESO[static_cast<int>(conversion.unidadDestino)];

    return resultado;
}

double convertir(ConversionTemperatura conversion, double valor) {

    // Declaracion de variable para almacenar el resultado de la conversion
    double resultado;

    // Pasar unidad de origen a Celsius
    if (conversion.unidadOrigen == CELSIUS) {
        // No hay que hacer nada
    }
    else if (conversion.unidadOrigen == FAHRENHEIT) {
        resultado = 5/9 * (valor - 32);
    }
    else if (conversion.unidadOrigen == KELVIN) {
        resultado = valor - 273.15;
    }

    // Pasar de Celsius a unidad de destino
    if (conversion.unidadDestino == CELSIUS) {
        // No hay que hacer nada
    }
    else if (conversion.unidadDestino == FAHRENHEIT) {
        resultado = 9/5 * resultado + 32;
    }
    else if (conversion.unidadDestino == KELVIN) {
        resultado += 273.15;
    }

    return resultado;
}


void mostrarMenu() {
    int opcion;

    int origen, destino;
    double valor;

    cout << "\nConversión de Unidades" << endl;
    cout << "Opcion 1. Convertir entre diferentes unidades de longitud" << endl;
    cout << "Opcion 2. Convertir entre diferentes unidades de peso" << endl;
    cout << "Opcion 3. Convertir entre diferentes unidades de temperatura" << endl;
    cout << "Opcion 4. Salir" << endl;

    cin >> opcion;

    // Validar entrada valida de las opciones (se indico que se podia asumir que las entradas siempre serian correctas en este caso)
    if (cin.fail()) {
        cin.clear(); // Limpiar el cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada
    }

    if (opcion == MENU_SALIR) {
        // Salir del programa
        return;
    }

    // switch-case para validar la entrada del menu
    switch (opcion)
    {
    case MENU_LONGITUD:
        // Struct para la conversion de longitud
        ConversionLongitud conversionL;
    
        // Menu de ingreso de unidades
        cout << "Seleccione la unidad de origen (1: Metro, 2: Kilometro, 3: Centimetro, 4: Milla, 5: Pulgada): ";
        cin >> origen;
        cout << "Seleccione la unidad de destino (1: Metro, 2: Kilometro, 3: Centimetro, 4: Milla, 5: Pulgada): ";
        cin >> destino;
        cout << "Ingrese el valor a convertir: ";
        cin >> valor;

        // Asignar valores a struct
        // Se disminuyen en 1 para ajustar a indices del enum
        conversionL.unidadOrigen = static_cast<longitud>(origen-1);
        conversionL.unidadDestino = static_cast<longitud>(destino-1);

        // Imprimir el resultado
        cout << "El resultado es: " << convertir(conversionL, valor) << endl;

        break;
    case MENU_PESO:
        // Struct para la conversion de peso
        ConversionPeso conversionP;

        // Menu de ingreso de unidades
        cout << "Seleccione la unidad de origen (1: Gramo, 2: Kilogramo, 3: Libra, 4: Onza): ";
        cin >> origen;
        cout << "Seleccione la unidad de destino (1: Gramo, 2: Kilogramo, 3: Libra, 4: Onza): ";
        cin >> destino;
        cout << "Ingrese el valor a convertir: ";
        cin >> valor;

        // Asignar valores a struct
        // Se disminuyen en 1 para ajustar a indices del enum
        conversionP.unidadOrigen = static_cast<peso>(origen-1);
        conversionP.unidadDestino = static_cast<peso>(destino-1);

        // Imprimir resultado de la conversion
        cout << "El resultado es: " << convertir(conversionP, valor) << endl;
        
        break;
        
    case MENU_TEMPERATURA:
        // Struct para la conversion de temperatura
        ConversionTemperatura conversionT;

        // Menu de ingreso de unidades
        cout << "Seleccione la unidad de origen (1: Celsius, 2: Fahrenheit, 3: Kelvin): ";
        cin >> origen;
        cout << "Seleccione la unidad de destino (1: Celsius, 2: Fahrenheit, 3: Kelvin): ";
        cin >> destino;
        cout << "Ingrese el valor a convertir: ";
        cin >> valor;
 
        // Asignar valores a struct
        // Se disminuyen en 1 para ajustar a indices del enum
        conversionT.unidadOrigen = static_cast<temperatura>(origen-1);
        conversionT.unidadDestino = static_cast<temperatura>(destino-1);

        // Imprimir el resultado de la conversion
        cout << "El resultado es: " << convertir(conversionT, valor) << endl;
        
        break;
    
    default:
        // Entrada no valida
        cout << "Opción inválida. Digite una opción de las mostradas en el menú." << endl;
    }

    // Repeticion recursiva del menu
    mostrarMenu();
}
