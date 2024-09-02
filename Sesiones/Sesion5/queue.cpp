/**
 * Queue / Cola: Principio FIFO
 * Primero que entra a la cola, es el primero que sale
 */

#include <iostream>

// Tamano maximo de la cola
#define SIZE 5

using namespace std;

// Clase Queue = Cola
class Queue {
    // Miembros privados
    private:
        // Array, indice inicial, indice final
        int items[SIZE], front, rear;

    // Miembros publicos
    public:
        // Constructor: Inicializa front y rear en -1
        Queue() {
            front = -1;
            rear = -1;
        }

        // Funcion para verificar si la cola esta llena
        bool isFull() {
            // Cuando front es 0 y rear SIZE -1 = Ocupa todo el array
            if (front == 0 && rear == SIZE - 1) {
                return true;
            }
            return false;
        }

        // Funcion para comprobar si la cola esta vacia
        bool isEmpty() {
            // Indice inicial es -1 (no hay elementos)
            if (front == -1)
                return true;
            else
                return false;
        }

        // Agregar al final de la cola
        void enQueue(int element) {
            // Si esta llena
            if (isFull()) {
                cout << "Queue is full";
            }
            // Si no esta llena
            else {
                // Si el indice inicial era -1
                if (front == -1) front = 0;
                rear++; // Aumentar el valor del indice final
                items[rear] = element; // Agregar elemento en el indice final
                cout << endl << "Inserted " << element << endl;
            }
        }

        // Funcion para quitar un elemento de la cola
        int deQueue() {
            // Declaracion de variable element
            int element;

            // Si esta vacia, no se pueden eliminar elementos
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return (-1); // Error
            } else {
                element = items[front]; // Elemento a quitar es el del indice inicial
                
                // Si indice frontal es mayor o igual que el final -> vacia
                if (front >= rear) {
                    front = -1;
                    rear = -1;
                } /* Queue tiene solo un elemento, entonces se reinician los valores de front y rear */
                else {
                    // Si no queda vacia, se aumenta el indice inicial (se ignora del rango el elemento quitado)
                    front++;
                }
                cout << "Deleted -> " << element << endl;
                return element; // Retornar el elemento eliminado
            }
        }

        void display() {
            /* Funcion para mostrar los elementos de Queue */
            int i; // Indice de recorrido de cola
            
            // Si esta vacia, se muestra un mensaje que lo indica
            if (isEmpty()) {
                cout << endl << "Empty Queue" << endl;
            } 
            // Si no esta vacia, se recorre
            else {
                cout << endl << "Front index-> " << front;
                cout << endl << "Items -> ";

                // Recorrer desde el indice inicial al final
                for (i = front; i <= rear; i++) {
                    cout << items[i] << " ";
                }
                cout << endl << "Rear index-> " << rear << endl;
            }
        }
};

int main() {

    // Declaracion de objeto de clase Queue
    Queue q;
    
    // deQueue no es posible para una cola vacia
    q.deQueue();

    // enQueue 5 elementos
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // Sexto elemento no se puede agregar porque la cola esta llena
    q.enQueue(6);

    // Mostrar cola llena
    q.display();

    // Eliminar el primer elemento con valor 1
    q.deQueue();

    // Mostrar cola sin primer elemento previo
    q.display();

    return 0;

}