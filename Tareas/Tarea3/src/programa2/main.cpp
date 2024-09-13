

#include "ListaCanciones.hpp"
#include "Cancion.hpp"
#include <iostream>

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

int main() {
    ListaCanciones lista;

    // Agregar canciones
    lista.insertarFinal(Cancion("C1", "A1", 1.5));
    lista.insertarFinal(Cancion("C2", "A2", 2.5));
    lista.insertarFinal(Cancion("C3", "A3", 3));

    int opcion;

    do {
        // Mostrar menú
        cout << "\n*-* Programa de Gestión de Canciones *-*" << endl;
        cout << "1. Insertar nueva canción" << endl;
        cout << "2. Eliminar una canción" << endl;
        cout << "3. Modificar una canción" << endl;
        cout << "4. Imprimir lista de canciones" << endl;
        cout << "5. Salir" << endl;

        cout << "Seleccione una opción: " << endl;
        cin >> opcion;

        string nombre, artista;
        double duracion;

        switch (opcion) {
            case OPT_INSERTAR_CANCION: {
                cout << "Nombre: ";
                cin >> nombre;

                cout << "Artista: ";
                cin >> artista;

                cout << "Duracion (min): ";
                cin >> duracion;

                lista.insertarFinal(Cancion(nombre, artista, duracion));

                break;
            }
            case OPT_ELIMINAR_CANCION: {
                cout << "Nombre de la canción a eliminar: ";
                cin >> nombre;
                lista.eliminarCancion(nombre);
                break;
            }
            case OPT_MODIFICAR_CANCION: {
                cout << "Nombre de la canción a modificar: ";
                cin >> nombre;
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

    } while(opcion != OPT_SALIR);

    return 0;
}