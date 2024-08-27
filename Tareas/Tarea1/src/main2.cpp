#include <iostream>
#include "programa2.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "Ingrese al menos un número en la línea de comando" << endl;
        return 1;
    }

    int largo = argc-1;
    int array[largo];


    for (int i = 0; i < largo; i++) {
        array[i] = stoi(argv[i+1]);
    }


    int opcion;

    do {
        cout << "\nCalculadora de Estadísticas y Búsqueda en un Arreglo" << endl;
        cout << "Opcion 1: Mostrar Estadística" << endl;
        cout << "Opcion 2: Buscar un número en el arreglo" << endl;
        cout << "Opcion 3: Salir" << endl;

        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Suma total: " << calcularSuma(array, largo) << endl;
                cout << "Promedio: " << calcularPromedio(array, largo) << endl;
                cout << "Número máximo: " << calcularMaximo(array, largo) << endl;
                cout << "Número mínimo: " << calcularMinimo(array, largo) << endl;
                break;
            case 2:
                buscarNumero(array, largo);
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Digite una opción de las mostradas en el menú.";
        }

    } while (opcion != 3);

    return 0;
}