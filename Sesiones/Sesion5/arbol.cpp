/**
 * Implementacion de un arbol
 * Cada nodo del arbol tiene nodos conectados a la izquierda y a la derecha
 * 
 * Raiz: Nodo mas alto del arbol
 * Arista: Conexion entre nodos
 * Altura: Distancia entre la raiz y el nodo mas bajo
 * Profundidad de un nodo: Distancia entre la raiz y el nodo
 * Grado: Numero total de ramas del nodo
 * Bosque: Conjunto de arboles separados
 */

#include <iostream>
using namespace std;

// Declaracion de estructura Node
struct Node {
    int data; // Dato almacenado en el nodo
    struct Node *left, *right; // Nodos vecinos
    
    // Constructor: Requiere que se ingrese la variable data
    Node(int data) {
        this->data = data;
        left = right = NULL; // Se inicializan los vecinos en NULL (sin hijos)
    }
};

/* 
Recorrido en preorder:
Primero la raiz, despues los nodos del subarbol izquierdo, y luego, los del subarbol derecho
 */
void preorderTraversal(struct Node *node) {
    // Condicion para indicar que se llego a un nodo hoja
    if (node == NULL)
        return;

    // Mostrar el data del raiz
    cout << node->data << "->";

    // Llamadas recursivas de la funcion hasta recorrer el lado izquierdo y luego el derecho
    preorderTraversal(node->left); // Subarbol izquierdo
    preorderTraversal(node->right); // Subarbol derecho
}


/* 
Recorrido en postorder:
Primero los nodos del subarbol izquierdo, despues los del subarbol derecho y finalmente, la raiz
 */
void postorderTraversal(struct Node *node) {
    // Condicion para indicar que se llego a un nodo hoja
    if (node == NULL)
        return;

    // Llamadas recursivas de la funcion
    postorderTraversal(node->left); // Subarbol izquierdo
    postorderTraversal(node->right); // Subarbol derecho

    cout << node->data << "->"; // Mostrar el data del raiz
}

/* 
Recorrido en orden:
Primero los nodos del subarbol izquierdo, despues la raiz y luego, los del subarbol derecho
 */
void inorderTraversal(struct Node *node) {
    // Condicion para indicar que se llego a un nodo hoja
    if (node == NULL)
        return;

    // Llamadas recursivas para recorrer con el orden establecido
    inorderTraversal(node->left); // Subarbol izquierdo
    cout << node->data << "->"; // Raiz
    inorderTraversal(node->right); // Subarbol derecho
}

int main() {
    // Inicializar nodo root (raiz)
    struct Node *root = new Node(1);

    // Vecinos de root
    root->left = new Node(12);
    root->right = new Node(9);

    // Vecinos del nodo 12
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    // Recorrido en orden
    cout << "Inorder traversal ";
    inorderTraversal(root);

    // Recorrido en preorder
    cout << "\nPreorder traversal ";
    preorderTraversal(root);

    // Recorrido en postorder
    cout << "\nPostorder traversal ";
    postorderTraversal(root);
    
    cout << endl; // Salto de linea extra al final

    return 0;
}
