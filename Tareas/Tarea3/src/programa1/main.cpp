/**
 * @file main.cpp
 * @brief Archivo que corresponde al punto de inicio de la ejecución del programa.
 * 
 * @details En este source file, se tiene definida a la función main(). En esta se imprime el menú del programa
 * recurrentemente, así como que se realiza la validación de las entradas del usuario para escoger opciones e ingresar
 * valores al programa.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 14/09/2024
 */

#include <iostream>
#include "ABB.hpp"

using namespace std;

/**
 * @enum OpcionesMenu
 * @brief Contiene las opciones del menú del programa.
 */
enum OpcionesMenu {
    OPT_INSERTAR_NODO = 1, 
    OPT_ELIMINAR_NODO,
    OPT_IMPRIMIR_ARBOL,
    OPT_ALTURA,
    OPT_BALANCEO,
    OPT_SALIR
};

/**
 * @brief Punto de entrada de ejecución del programa.
 * 
 * Se encarga de mostrar el menú y de validar las entradas del usuario, así como de solicitar los datos
 * requeridos dependiendo de la opción escogida.
 * 
 * @return Código de estado del programa.
 */
int main() {
    // Declaración de objeto ABB que representa al árbol binario de búsqueda
    ABB arbol;
    
    // Agregar valores predefinidos al árbol
    arbol.insertar(15);
    arbol.insertar(10);
    arbol.insertar(20);
    arbol.insertar(8);
    arbol.insertar(12);
    arbol.insertar(17);
    arbol.insertar(25);

    // Declaración de variables utilizadas para recibir datos del usuario
    int opcion, valor;

    // do-while loop: Muestra el menú repetidamente
    do {
        // Imprimir menú
        cout << "\n*-* Programa de ABB con Verificación y Balanceo *-*" << endl;
        cout << "1. Insertar un nodo" << endl;
        cout << "2. Eliminar un nodo" << endl;
        cout << "3. Imprimir el árbol" << endl;
        cout << "4. Calcular la altura del árbol" << endl;
        cout << "5. Verificar si el árbol está balanceado" << endl;
        cout << "6. Salir" << endl;

        // Input de opcion escogida por el usuario
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Validación de selección de opcion
        switch (opcion) {
            case OPT_INSERTAR_NODO: {

                // Input de valor a insertar
                cout << "Ingrese el valor para insertar en el ABB: ";
                cin >> valor;

                arbol.insertar(valor);
                break;
            }
            
            case OPT_ELIMINAR_NODO: {

                // Input de valor a eliminar dentro del ABB
                cout << "Ingrese el valor a eliminar en el ABB: ";
                cin >> valor;

                arbol.eliminar(valor);
                break;
            }
            case OPT_IMPRIMIR_ARBOL: {

                // Imprimir arbol en un recorrido en orden
                cout << "InOrder Traversal: ";
                
                arbol.inOrderTraversal();
                break;
            }
            case OPT_ALTURA: {
                // Imprimir altura del ABB
                cout << "Altura del ABB: " << arbol.calcularAltura() << endl;
                break;
            }
            case OPT_BALANCEO: {
                // Imprimir condición de balanceo a partir de función miembro estaBalanceado()
                if (arbol.estaBalanceado()) {
                    cout << "El ABB está balanceado" << endl;
                }
                else {
                    cout << "El ABB no está balanceado" << endl;
                }
                break;
            }
            case OPT_SALIR: {
                // Salir del programa
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                // Opcion numerica invalida ingresada
                cout << "Opción inválida. Intente nuevamente" << endl;
                break;
            }
        }

    } while (opcion != OPT_SALIR); // Condición de repetición de do-while loop

    return 0;
}