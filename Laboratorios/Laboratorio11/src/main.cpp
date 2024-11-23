/**
 * @file main.cpp
 * @brief Programa principal para probar las funcionalidades de la clase BinarySearchTree.
 * @details Este archivo contiene un ejemplo de uso de la clase `BinarySearchTree`, incluye
 *          la inserción de valores, la impresión en orden ascendente y la búsqueda del ancestro 
 *          común más cercano (LCA) de dos nodos.
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 22/11/2024
 */

#include "binarySearchTree.hpp"


/**
 * @brief Función principal del programa.
 * @details Demuestra el uso de las funcionalidades de `BinarySearchTree`:
 *          - Insertar nodos en el árbol.
 *          - Imprime el árbol en orden ascendente.
 *          - Cálculo del ancestro común más cercano (LCA) entre dos nodos.
 * @return `int` Código de salida del programa.
 */
int main() {
    BinarySearchTree bst; // Crea una instancia del árbol binario de búsqueda

    // Inserción de nodos en el árbol
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(12);
    bst.insert(18);

    /*
    Representación visual del árbol insertado
         20
        /  \
      10    30
     /  \
    5    15
        /  \
      12    18
    */

    // Imprime los valores del árbol en orden
    std::cout << "Árbol en orden: ";
    bst.printInOrder();

    // Calcula y muestra el ancestro común más cercano entre diferentes nodos
    try {
        int v1 = 12, v2 = 18;
        std::cout << "El ancestro común más cercano de " << v1 << " y " << v2 << " es: "
                  << bst.findLowestCommonAncestor(v1, v2) << std::endl;

        v1 = 5; v2 = 30;
        std::cout << "El ancestro común más cercano de " << v1 << " y " << v2 << " es: "
                  << bst.findLowestCommonAncestor(v1, v2) << std::endl;
    } catch (const std::exception& e) {
        // Manejo de errores si se lanza una excepción
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
