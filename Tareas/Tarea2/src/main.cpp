
#include <iostream>

using namespace std;

int main() {

    int opcion;

    do {
        cout << "Sistema de Gestion de Tienda en Linea" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Registrar cliente" << endl;
        cout << "3. Agregar producto al carrito" << endl;
        cout << "4. Procesar compra" << endl;
        cout << "5. Salir" << endl;

        cin >> opcion;

        switch (opcion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        
        default:
            cout << "Opcion invalida. Intente de nuevo con una opcion de las que se muestra en el menu." << endl;
            break;
        }
        


    } while(opcion != 5);


    return 0;
}