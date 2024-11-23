/**
 * @file BinarySearchTree.hpp
 * @brief Declaración de las clases y métodos para el Árbol Binario de Búsqueda (ABB).
 * @details Este archivo contiene la definición de la estructura `TreeNode` y la clase `BinarySearchTree`. 
 *          `TreeNode` representa un nodo individual del árbol, mientras que `BinarySearchTree` proporciona
 *          métodos para insertar elementos, buscar el ancestro común más cercano y realizar un recorrido 
 *          en orden.
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 22/11/2024
 */

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <stdexcept>

/**
 * @brief Representa un nodo en un Árbol Binario de Búsqueda (ABB).
 * @details Cada nodo contiene un valor entero y punteros a sus nodos izquierdo y derecho.
 */
struct TreeNode {
    /// @brief Valor que contiene el nodo del árbol.
    int value;

    /// @brief Puntero al nodo izquierdo.
    TreeNode* left;

    /// @brief Puntero al nodo derecho.
    TreeNode* right;

    /**
     * @brief Constructor que inicializa el nodo con un valor dado.
     * @param val Valor que va a ser asignado al nodo en cuestión.
     */
    TreeNode(int val);
};


/**
 * @brief Clase de la implementación del Árbol Binario de Búsqueda (ABB).
 * @details Proporciona métodos para insertar elementos, encontrar el ancestro común más cercano (LCA),
 *          buscar elementos y realizar un recorrido en orden (in-order traversal). 
 */
class BinarySearchTree {
    private:
        /// @brief Raíz del árbol binario.
        TreeNode* root;

        /**
         * @brief Función auxiliar que inserta un nuevo nodo en el árbol de forma recursiva.
         * @details Crea un nodo si el nodo actual es nulo. Si no, busca la posición correcta para insertar
         *          el valor comparando con el valor del nodo actual.
         * @param node Nodo actual desde donde se inicia la inserción.
         * @param value Valor que se desea insertar en el árbol.
         * @return `TreeNode*` Nodo actualizado tras la inserción.
         */
        TreeNode* insert(TreeNode* node, int value);

        /**
         * @brief Función auxiliar que encuentra el ancestro común más cercano (LCA) de dos valores dados.
         * @details Explora el árbol de forma recursiva hasta encontrar el nodo donde los dos valores divergen.
         * 
         * @param node Nodo actual desde donde se realiza la búsqueda.
         * @param v1 Primer valor para encontrar el LCA.
         * @param v2 Segundo valor para encontrar el LCA.
         * @return `TreeNode*` Nodo que representa el LCA de v1 y v2.
         */
        TreeNode* findLCA(TreeNode* node, int v1, int v2);

        /**
         * @brief Función auxiliar que realiza un in-order traversal del árbol.
         * @details Imprime los valores en el árbol en orden ascendente.
         * 
         * @param node Nodo actual desde donde se inicia el recorrido.
         * @return `void`
         */
        void inOrderTraversal(TreeNode* node);

        /**
         * @brief Función auxiliar que busca un valor específico en el árbol.
         * @details Recorre el árbol de forma recursiva para determinar si el valor existe.
         * 
         * @param node Nodo actual desde donde se inicia la búsqueda.
         * @param value Valor a buscar en el árbol.
         * @return `bool` Verdadero si el valor existe, falso en caso contrario.
         */
        bool search(TreeNode* node, int value);

    public:
        /**
         * @brief Constructor de la clase.
         * @details Inicializa el árbol con una raíz nula.
         */
        BinarySearchTree();

        /**
         * @brief Inserta un valor en el árbol binario de búsqueda.
         * @details Utiliza una función auxiliar recursiva para buscar la posición correcta y realizar la inserción.
         * 
         * @param value Valor a insertar en el árbol.
         * @return `void`
         */
        void insert(int value);

        /**
         * @brief Encuentra el ancestro común más cercano (LCA) entre dos valores.
         * @details Valida que ambos valores existan en el árbol antes de buscar el LCA.
         * 
         * @param v1 Primer valor.
         * @param v2 Segundo valor.
         * @return `int` Valor del nodo que representa el LCA.
         * 
         * @throws `std::invalid_argument` Si uno o ambos valores no existen en el árbol.
         * @throws `std::runtime_error` Si no se encuentra el LCA.
         */
        int findLowestCommonAncestor(int v1, int v2);

        /**
         * @brief Imprime el árbol en orden.
         * @details Realiza un recorrido en orden ascendente utilizando la función auxiliar `inOrderTraversal`.
         * 
         * @return `void`
         */
        void printInOrder();
};

#endif // BINARY_SEARCH_TREE_HPP