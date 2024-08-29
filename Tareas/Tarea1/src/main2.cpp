/**
 * @file main2.hpp
 * @brief Archivo que contiene la función main() .
 * 
 * En este archivo se valida el ingreso de argumentos por la línea de comandos, se muestra
 * el menú del programa y se llaman las funciones correspondientes.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 30/08/2024
 */

#include "programa2.hpp"

using namespace std;

/**
 * @brief Punto de entrada principal del programa.
 * 
 * Esta función inicializa el programa y gestiona el ciclo principal de ejecución.
 * 
 * @return Código de estado del programa.
 */
int main(int argc, char* argv[]) {

    // Se verifica que se hayan ingresado 2 o mas argumentos en la linea de comando
    if (argc < 2) {
        cout << "Ingrese al menos un número en la línea de comando" << endl;
        return -1;
    }

    int largo = argc-1; // Quitar el nombre del programa en argc
    int array[largo]; // Declaracion de arreglo de enteros
    int* ptrArray = array; // Puntero que apunta al primer elemento del array

    // Asignar al arreglo cada entrada de argv por medio de un puntero (excluyendo el nombre argv[0])
    for (int i = 0; i < largo; i++) {
        *(ptrArray+i) = stoi(argv[i+1]); // Convertir a enteros cada entrada de argv
    }

    // Declaracion de variable para escoger opciones en el menu
    int opcion;

    // do-while loop
    do {
        // Imprimir menu
        cout << "\nCalculadora de Estadísticas y Búsqueda en un Arreglo" << endl;
        cout << "Opcion 1: Mostrar Estadística" << endl;
        cout << "Opcion 2: Buscar un número en el arreglo" << endl;
        cout << "Opcion 3: Salir" << endl;

        // Ingreso de opcion por usuario
        cin >> opcion;

        // Validacion de opcion
        switch (opcion) {
            case MOSTRAR_ESTADISTICAS:
                // Caso 1: Mostrar estadisticas
                cout << "Suma total: " << calcularSuma(array, largo) << endl;
                cout << "Promedio: " << calcularPromedio(array, largo) << endl;
                cout << "Número máximo: " << calcularMaximo(array, largo) << endl;
                cout << "Número mínimo: " << calcularMinimo(array, largo) << endl;
                break;
            case BUSCAR_NUMERO:
                // Caso 2: Buscar numero en el arreglo
                buscarNumero(array, largo);
                break;
            case SALIR_PROGRAMA:
                // Salir del programa
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                // Caso por defecto
                cout << "Opción inválida. Digite una opción de las mostradas en el menú.";
        }

    } while (opcion != SALIR_PROGRAMA); // Se repite el loop hasta que se ingrese la opcion de salir

    return 0;
}