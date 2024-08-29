/**
 * @file main1.cpp
 * @brief Archivo que contiene la función main().
 * 
 * @details En este archivo se llama la función mostrarMenu(), la cual se repite recursivamente
 * para poder realizar numerosas conversiones si se desea.
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
 * @brief Punto de entrada principal del programa.
 * 
 * Esta función inicializa el programa y gestiona el ciclo principal de ejecución.
 * 
 * @return Código de estado del programa.
 */
int main() {
    // Repeticion de forma recursiva del menu
    mostrarMenu();

    cout << "Saliendo del programa..." << endl;

    return 0;
}