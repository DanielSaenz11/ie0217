/**
 * @file main.cpp
 * @brief Archivo que contiene a la función main() y el menú del programa.
 * 
 * @details En este source file se implementa el menú del programa de lista de canciones y el sistema de
 * validación de entradas del usuario.
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

#include "ListaCanciones.hpp" // Clase ListaCanciones
#include "Cancion.hpp" // Clase Cancion
#include <iostream>
#include <limits> // Para std::numeric_limits

using namespace std;

/**
 * @enum OpcionesMenu
 * @brief Contiene las opciones del menú del programa.
 */
enum OpcionesMenu {
    OPT_INSERTAR_CANCION = 1, 
    OPT_ELIMINAR_CANCION,
    OPT_MODIFICAR_CANCION,
    OPT_IMPRIMIR_CANCIONES,
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

    // Declaraciónd de lista de canciones
    ListaCanciones lista;

    // Agregar canciones al final de la lista
    lista.insertarFinal(Cancion("Not Like Us", "Kendrick Lamar", 4.5));
    lista.insertarFinal(Cancion("Rockstar", "Post Malone", 4));
    lista.insertarFinal(Cancion("Runaway", "Kanye West", 4.5));

    int opcion; // Opcion ingresada por el usuario

    // do-while loop: Muestra el menú de forma recurrente
    do {
        // Mostrar menú
        cout << "\n*-* Programa de Gestión de Canciones *-*" << endl;
        cout << "1. Insertar nueva canción" << endl;
        cout << "2. Eliminar una canción" << endl;
        cout << "3. Modificar una canción" << endl;
        cout << "4. Imprimir lista de canciones" << endl;
        cout << "5. Salir" << endl;

        // Ingreso de opción
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Declaración de variables utilizadas para recibir datos del usuario
        string nombre, artista;
        double duracion;

        // Validación de opciones
        switch (opcion) {
            case OPT_INSERTAR_CANCION: {

                // Solicitar datos de la canción a agregar

                cout << "Nombre: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer de entrada cuando antes hubo un ingreso con cin
                getline(cin, nombre); // Leer línea

                cout << "Artista: ";
                getline(cin, artista); // Leer línea

                cout << "Duracion (min): ";
                cin >> duracion;

                // Llamado de función para insertar canción -> Se solicita el tipo de inserción
                lista.insertarCancion(Cancion(nombre, artista, duracion));

                break;
            }
            case OPT_ELIMINAR_CANCION: {
                cout << "Nombre de la canción a eliminar: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer de entrada cuando antes hubo un ingreso con cin
                getline(cin, nombre); // Leer línea

                lista.eliminarCancion(nombre);
                break;
            }
            case OPT_MODIFICAR_CANCION: {
                cout << "Nombre de la canción a modificar: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer de entrada cuando antes hubo un ingreso con cin
                getline(cin, nombre); // Leer línea

                lista.modificarCancion(nombre);
                break;
            }
            case OPT_IMPRIMIR_CANCIONES: {
                lista.imprimirLista();
                break;
            }
            case OPT_SALIR: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }

    } while(opcion != OPT_SALIR); // Condición de repetición de do-while loop

    return 0;
}