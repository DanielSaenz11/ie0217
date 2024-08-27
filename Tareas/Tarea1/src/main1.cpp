#include <iostream>
#include "programa1.hpp"

using namespace std;

int main() {
    
    int opcion;

    int origen, destino;
    double valor;

    do {
        cout << "\nConversión de Unidades" << endl;
        cout << "Opcion 1. Convertir entre diferentes unidades de longitud" << endl;
        cout << "Opcion 2. Convertir entre diferentes unidades de peso" << endl;
        cout << "Opcion 3. Convertir entre diferentes unidades de temperatura" << endl;
        cout << "Opcion 4. Salir" << endl;

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            break;
        case 2:
            struct ConversionPeso conversion;

            cout << "Seleccione la unidad de origen (1: Gramo, 2: Kilogramo, 3: Libra, 4: Onza): ";
            cin >> origen;
            cout << "Seleccione la unidad de destino (1: Gramo, 2: Kilogramo, 3: Libra, 4: Onza): ";
            cin >> destino;
            cout << "Ingrese el valor a convertir: ";
            cin >> valor;

            conversion.unidadOrigen = (Peso)origen;
            conversion.unidadDestino = (Peso)destino;

            convertir(conversion, valor);
            
            break;
            
        case 3:
            
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        
        default:
            cout << "Opción inválida. Digite una opción de las mostradas en el menú.";
        }

    } while (opcion != 4);



    return 0;
}