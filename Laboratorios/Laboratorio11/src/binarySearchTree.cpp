/**
 * @file BinarySearchTree.cpp
 * @brief Implementación de un Árbol Binario de Búsqueda.
 * @details Este archivo contiene la implementación de las funciones y métodos de la clase 
 *          `BinarySearchTree` y el constructor del `TreeNode`. Se implementan las operaciones 
 *          de inserción, búsqueda, recorridos en orden y la determinación del ancestro común 
 *          más cercano (LCA).
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 22/11/2024
 */

#include "binarySearchTree.hpp"

// Constructor del struct nodo: Inicializa un nodo con el valor proporcionado
TreeNode::TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}


// Constructor de la clase BinarySearchTree: Inicializa un árbol vacío con raíz nullptr
BinarySearchTree::BinarySearchTree() : root(nullptr) {}


// Definición de función auxiliar que inserta un nuevo nodo en el árbol
TreeNode* BinarySearchTree::insert(TreeNode* node, int value) {
    // Si el nodo actual es nulo, se crea un nuevo nodo con el valor
    if (node == nullptr) {
        return new TreeNode(value);
    }

    // Si el valor es menor al valor del nodo actual, se inserta en el subárbol izquierdo de forma recursiva
    if (value < node->value) {
        node->left = insert(node->left, value);
    }
    // Si el valor es mayor al valor del nodo actual, se inserta en el subárbol derecho de forma recursiva
    else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    
    // Retorna el nodo actual 
    return node;
}


// Definición de función auxiliar para encontrar el ancestro común más cercano (LCA)
TreeNode* BinarySearchTree::findLCA(TreeNode* node, int v1, int v2) {
    // Si el nodo actual es nulo, no se encontró el ancestro común
    if (node == nullptr) {
        return nullptr;
    }

    // Si ambos valores son menores al valor del nodo actual, buscar recursivamente en el subárbol izquierdo
    if (v1 < node->value && v2 < node->value) {
        return findLCA(node->left, v1, v2);
    }
    // Si ambos valores son mayores al valor del nodo actual, buscar recursivamente en el subárbol derecho
    if (v1 > node->value && v2 > node->value) {
        return findLCA(node->right, v1, v2);
    }

    // Si los valores están en ramas diferentes o uno es igual al nodo actual, se encontró el LCA
    return node;
}


// Definición de función auxiliar para realizar un in-order traversal
void BinarySearchTree::inOrderTraversal(TreeNode* node) {
    // Si el nodo actual es nulo, se terminó el recorrido
    if (node == nullptr) return;

    /* Recorrido recursivo del subárbol izquierdo -> nodo actual -> subárbol derecho */

    // Recorre el subárbol izquierdo en orden
    inOrderTraversal(node->left);

    // Imprime el valor del nodo actual
    std::cout << node->value << " ";

    // Recorre el subárbol derecho en orden
    inOrderTraversal(node->right);
}


// Definición de función auxiliar para buscar un valor en el árbol
bool BinarySearchTree::search(TreeNode* node, int value) {
    // Si el nodo actual es nulo, el valor buscado no existe en el árbol
    if (node == nullptr) return false;

    // Si el valor del nodo actual coincide, se retorna true
    if (node->value == value) return true;

    // Si el valor es menor, busca en el subárbol izquierdo recursivamente
    if (value < node->value) return search(node->left, value);

    // Si el valor es mayor, busca en el subárbol derecho recursivamente
    return search(node->right, value);
}


// Definición de método público para insertar un valor en el árbol
void BinarySearchTree::insert(int value) {
    // Llama a la función auxiliar para insertar el valor en el árbol
    root = insert(root, value);
}


// Definición de método público para encontrar el ancestro común más cercano
int BinarySearchTree::findLowestCommonAncestor(int v1, int v2) {
    // Comprueba que ambos valores existan en el árbol
    if (!search(root, v1) || !search(root, v2)) {
        throw std::invalid_argument("Uno o ambos valores no existen en el árbol.");
    }

    // Busca el LCA con la función auxiliar
    TreeNode* lca = findLCA(root, v1, v2);

    // Si no se encuentra un LCA válido, lanza una excepción
    if (lca == nullptr) {
        throw std::runtime_error("No se encontró el ancestro común.");
    }

    // Retorna el valor del LCA encontrado
    return lca->value;
}


// Definición de método público para imprimir el árbol en orden
void BinarySearchTree::printInOrder() {
    // Llama a la función auxiliar para iniciar el recorrido desde la raíz
    inOrderTraversal(root);

    // Salto de línea
    std::cout << std::endl;
}
