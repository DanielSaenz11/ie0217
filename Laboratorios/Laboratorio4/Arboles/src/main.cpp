// Incluir header file que contiene la declaracion de la clase ArbolBinarioBusqueda
#include "ArbolBinarioBusqueda.hpp"
#include <iostream>

// Funcion main(): Punto de entrada del programa
int main() {
    // Declaracion de objeto de clase arbol
    ArbolBinarioBusqueda arbol;

    // Variable para almacenar las opciones del menu y el valor ingresado por el usuario
    int opcion, valor;

    // do-while loop para mostrar el menu
    do {
        std::cout << "1. Insertar un nodo\n";
        std::cout << "2. Recorrido en Preorden\n";
        std::cout << "3. Recorrido en Inorden\n";
        std::cout << "4. Recorrido en Postorden\n";
        std::cout << "5. Buscar un valor\n";
        std::cout << "6. Altura del árbol\n";
        std::cout << "7. Verificar si el árbol está balanceado\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opción: ";
        
        // Ingreso del usuario de opcion
        std::cin >> opcion;

        // switch-case para validar la variable opcion
        switch (opcion) {
            case 1:
                // Insertar un nodo en el arbol binario de busqueda
                std::cout << "Ingrese un valor: ";
                std::cin >> valor;
                arbol.insertar(valor); // Llamada de la funcion insertar() -> publica
                break;
            case 2:
                // Recorrido en preorden del arbol
                arbol.preOrden();
                break;
            case 3:
                // Recorrido en orden del arbol
                arbol.inOrden();
                break;
            case 4:
                // Recorrido en postorden del arbol
                arbol.postOrden();
                break;
            case 5:
                // Ingreso del valor a buscar en el arbol binario de busqueda
                std::cout << "Ingrese un valor a buscar: ";
                std::cin >> valor;

                // Llamada de la funcion para buscar en el arbol
                if (arbol.buscar(valor)) {
                    // Si retorna true, se imprime un mensaje positivo
                    std::cout << "Valor encontrado.\n";
                } else {
                    // Si retorna false, se imprime un mensaje negativo
                    std::cout << "Valor no encontrado.\n";
                }
                break;
            case 6:
                // Impresion de la altura del arbol
                std::cout << "Altura del árbol: " << arbol.altura() << std::endl;
                break;
            case 7:
                // Verificacion si el arbol esta balanceado
                if (arbol.estaBalanceado()) {
                    // Caso true
                    std::cout << "El árbol está balanceado.\n";
                } 
                else {
                    // Caso false
                    std::cout << "El árbol no está balanceado.\n";
                }
                break;
            case 8:
                // Ingreso de opcion de salida del programa
                std::cout << "Saliendo...\n";
                break;
            default:
                // Si se ingreso una opcion que no esta contemplada en los casos
                std::cout << "Opción inválida.\n";
        }
    } while (opcion != 8); // Se sale del do-while si se ingresa la opcion 8

    return 0;
}
