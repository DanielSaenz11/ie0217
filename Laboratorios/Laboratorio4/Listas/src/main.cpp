// Incluir header file con definicion de lista enlazada
#include "ListaEnlazada.hpp"
#include <iostream>

// Funcion main(): Punto de entrada del programa
int main() {

    // Inicializar struct ListaEnlazada
    ListaEnlazada lista;
    
    // Variable para escoger la opcion del menu y el valor ingresado de nodo
    int opcion, valor;

    // do-while loop para mostrar el menu repetidamente
    do {

        // Impresion del menu
        std::cout << "1. Insertar al inicio\n";
        std::cout << "2. Insertar al final\n";
        std::cout << "3. Eliminar\n";
        std::cout << "4. Imprimir lista\n";
        std::cout << "5. Buscar en la lista\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción: ";
        
        // Ingreso de la opcion
        std::cin >> opcion;

        // switch-case para validar la entrada de opcion
        switch (opcion) {
            case 1:
                // Ingresa un valor del usuario y lo inserta al inicio de la lista
                std::cout << "Ingrese un valor: ";
                std::cin >> valor;
                lista.insertarInicio(valor); // Llamada de la funcion insertarInicio()
                break;
            case 2:
                // Ingresa un valor del usuario y lo inserta al final
                std::cout << "Ingrese un valor: ";
                std::cin >> valor;
                lista.insertarFinal(valor); // Llamada de la funcion insertarFinal()
                break;
            case 3:
                // Ingresa un valor del usuario para buscar un nodo con ese y eliminarlo
                std::cout << "Ingrese un valor a eliminar: ";
                std::cin >> valor;
                lista.eliminar(valor); // Llamada de la funcion eliminar() para eliminar nodo
                break;
            case 4:
                // Imprimir lista enlazada completa
                lista.imprimir();
                break;
            case 5:
                // Ingresa un valor del usuario para determinar si se encuentra o no en la lista
                std::cout << "Ingrese un valor a buscar: ";
                std::cin >> valor;

                // Si la llamada de la funcion miembro buscar() retorna true
                if (lista.buscar(valor)) {
                    std::cout << "Valor encontrado.\n"; // Se imprime un mensaje positivo
                } 
                // Si se retorna false
                else {
                    std::cout << "Valor no encontrado.\n"; // Se imprime un mensaje negativo
                }
                break;
            case 6:
                // Ingreso de opcion para salir del programa
                // Se ejecuta el destructor automaticamente
                std::cout << "Saliendo...\n";
                break;
            default:
                // Si se ingreso una opcion que no se encuentra en los casos
                std::cout << "Opción inválida.\n";
        }
    } while (opcion != 6); // Se repite el loop hasta que se ingrese un 6 -> salir

    return 0;
}
