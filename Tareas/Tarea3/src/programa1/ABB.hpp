/**
 * @file ABB.hpp
 * @brief Archivo que contiene la declaración de la clase ABB (Árbol binario de búsqueda).
 * 
 * @details En este header file se declara los atributos y miembros de la clase ABB, que corresponde
 * a la implementación de las funciones para un árbol binario de búsqueda.
 * Se dividieron las funciones miembro con especificadores de acceso públicos y privados, de tal forma que
 * los públicos no tienen referencia del nodo raíz.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 14/09/2024
 */

#ifndef ABB_HPP
#define ABB_HPP

#include "NodoABB.hpp" // Contiene la declaración del struct Nodo del árbol

/**
 * @class ABB
 * @brief Representa un árbol binario de búsqueda
 * 
 * La clase ABB almacena la raíz del árbol como un nodo privado.
 * Incluye métodos como el constructor, destructor y funciones miembro para recorrer el árbol en orden, insertar
 * y eliminar nodos, calcular la altura del ABB y comprobar si está balanceado.
 */
class ABB {
    public:

        /**
         * @brief Constructor de la clase ABB
         * 
         * Inicializa un objeto de la clase ABB (árbol binario de búsqueda) y el nodo raíz como nullptr.
         */
        ABB();

        /**
         * @brief Destructor de la clase ABB
         * 
         * Llama la función miembro destruirArbol() para liberar la memoria de los nodos del ABB de forma
         * recursiva.
         */
        ~ABB();

        /**
         * @brief Inserta un nuevo valor en el ABB de forma recursiva.
         *
         * Esta función inserta un valor en su posición adecuada dentro del ABB de manera recursiva. 
         * Si el nodo parámetro es nullptr, crea un nuevo nodo con el valor dado. Si el valor es 
         * menor que el dato del nodo actual, lo inserta en el subárbol izquierdo. En caso contrario, lo inserta 
         * en el subárbol derecho.
         *
         * @param valor El valor entero que se va a insertar en el ABB.
         * @return void
         */
        void insertar(int valor);
        
        /**
         * @brief Elimina un nodo específico del ABB.
         *
         * Esta función elimina un nodo del ABB que contiene el valor especificado.
         * Reorganiza los nodos del árbol de manera adecuada para mantener las propiedades del ABB después
         * de la eliminación. Si el nodo a eliminar tiene dos hijos, se reemplaza con el nodo sustituto (el más pequeño 
         * del subárbol derecho). Si tiene un solo hijo o es una hoja, simplemente se elimina.
         *
         * @param valor Valor del nodo que se desea eliminar del árbol.
         * @return void
         */
        void eliminar(int valor);

        /**
         * @brief Imprime el recorrido en orden del ABB
         * 
         * El recorrido se realiza de forma recursiva de la forma: subarbol izquierdo -> raíz -> subarbol derecho.
         * 
         * @return void
         */
        void inOrderTraversal() const;

        /**
         * @brief Calcula la altura del ABB
         * 
         * La altura consiste en el camino más largo desde nodo raíz hasta un nodo hoja.
         * 
         * @return Valor entero de la altura
         */
        int calcularAltura() const;

        /**
         * @brief Verifica si el ABB está balanceado o no
         * 
         * Un árbol está balanceado si para cada nodo, la diferencia de altura entre el subarbol izquierdo
         * y el subarbol derecho no es mayor que 1. Esta función utiliza una implementación recursiva para 
         * verificar esta propiedad en todo el árbol.
         * 
         * @return Booleano para indicar si está balanceado
         */
        bool estaBalanceado() const;

    private:
        /// @brief Nodo raíz del ABB
        Nodo *raiz;

        /**
         * @brief Inserta un nuevo valor en el ABB de forma recursiva.
         *
         * Esta función inserta un valor en su posición adecuada dentro del ABB de manera recursiva. 
         * Si el nodo parámetro es nullptr, crea un nuevo nodo con el valor dado. Si el valor es 
         * menor que el dato del nodo actual, lo inserta en el subárbol izquierdo. En caso contrario, lo inserta 
         * en el subárbol derecho.
         * 
         * Se implementa como función miembro para tener acceso al nodo raíz.
         *
         * @param nodo El puntero al nodo actual del árbol.
         * @param valor El valor entero que se va a insertar en el ABB.
         * @return Nodo* El puntero al nodo actual (ya sea uno nuevo o el nodo existente modificado).
         */
        Nodo* insertar(Nodo *nodo, int valor);
        
        /**
         * @brief Elimina un nodo específico del ABB.
         *
         * Esta función elimina un nodo del ABB que contiene el valor especificado.
         * Reorganiza los nodos del árbol de manera adecuada para mantener las propiedades del ABB después
         * de la eliminación. Si el nodo a eliminar tiene dos hijos, se reemplaza con el nodo sustituto (el más pequeño 
         * del subárbol derecho). Si tiene un solo hijo o es una hoja, simplemente se elimina.
         * 
         * Se implementa como función miembro para tener acceso al nodo raíz.
         *
         * @param nodo Puntero al nodo actual (o raíz del subárbol) desde donde se busca el valor a eliminar.
         * @param valor Valor del nodo que se desea eliminar del árbol.
         * @return Nodo* El nuevo nodo raíz del subárbol después de la eliminación, o nullptr si el subárbol queda vacío.
         */
        Nodo* eliminar(Nodo *nodo, int valor);

        /**
         * @brief Función miembro privada para encontrar el mínimo nodo de la parte derecha de un subárbol
         * 
         * Se utiliza dentro de la función eliminar para encontrar el nodo sustituto en el caso de que
         * se desee eliminar un nodo con dos hijos.
         * 
         * @param nodo Nodo raíz del subárbol
         * @return Nodo con menor valor dentro de la parte derecha del subárbol
         */
        Nodo* encontrarMinimo(Nodo *nodo);

        /**
         * @brief Imprime el recorrido en orden del ABB
         * 
         * El recorrido se realiza de forma recursiva de la forma: subarbol izquierdo -> raíz -> subarbol derecho.
         * 
         * Se implementa como función miembro para tener acceso al nodo raíz.
         * 
         * @param nodo Puntero al nodo actual del ABB
         * @return void
         */
        void inOrderTraversal(Nodo *nodo) const;

        /**
         * @brief Calcula la altura del ABB
         * 
         * La altura consiste en el camino más largo desde nodo raíz hasta un nodo hoja.
         * 
         * Se implementa como función miembro para tener acceso al nodo raíz.
         * 
         * @param nodo Puntero al nodo actual (o raíz del subárbol) donde se está calculando su altura.
         * @return Valor entero de la altura
         */
        int calcularAltura(Nodo *nodo) const;

        /**
         * @brief Comprueba si el ABB está balanceado o no
         * 
         * Un árbol está balanceado si para cada nodo, la diferencia de altura entre el subarbol izquierdo
         * y el subarbol derecho no es mayor que 1. Esta función utiliza una implementación recursiva para 
         * verificar esta propiedad en todo el árbol.
         * 
         * @param nodo Puntero al nodo actual (o raíz del subarbol) donde se está comprobando si está balanceado.
         * @return Booleano para indicar si está balanceado.
         */
        bool estaBalanceado(Nodo *nodo) const;

        /**
         * @brief Libera la memoria del ABB
         * 
         * Se utiliza una implementación recursiva para liberar la memoria del ABB, de forma que elimina primero el subarbol
         * izquierdo, luego el subarbol derecho y finalmente la raíz.
         * 
         * @param nodo Puntero al nodo actual (o raíz del subarbol) que se está liberando la memoria
         * @return void  
         */
        void destruirArbol(Nodo* nodo);
};

#endif // ABB_HPP