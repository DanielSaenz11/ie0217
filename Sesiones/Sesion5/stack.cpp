/**
 * Stack / Pila: Principio LIFO
 * Last in -> First out
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

// Definir el largo maximo de la pila
#define MAX 10

// Tamano real de la pila (se renombro la variable porque se señalaba como ambigua)
int stack_size = 0;

// Creacion de stack
struct stack {
    int items[MAX]; // Arreglo de enteros
    int top; // Entrada maxima ocupada
};
typedef struct stack st;

// Funcion para inicializar un stack
void createEmptyStack(st *s) {
    s->top = -1; // Coloca su entrada maxima ocupada en -1 -> vacio
}

// Revisar si el stack esta lleno
int isfull(st *s) {
    // Si la posicion maxima ocupada es el tamano -1 -> lleno
    if (s->top == MAX - 1) {
        return 1; // Lleno
    }
    else
        return 0; // Todavia no esta lleno
}

// Revisar si el stack esta vacio
int isempty(st *s) {
    // Si la posicion maxima llena es -1
    if (s->top == -1) {
        return 1; // Vacio
    }
    else
        return 0; // Al menos un elemento
}

// Agregar elementos al stack
void push(st *s, int newitem) {
    // Si esta lleno, no se puede agregar
    if (isfull(s)) {
        cout << "STACK FULL" << endl;
    } else {
        s->top++; // Se aumenta la posicion maxima llena
        s->items[s->top] = newitem; // Agregar el item en la nueva posicion top
        stack_size++; // Se coloco dentro del else porque sino, disminuia el stack_size aunque estuviera vacia
    }
}

// Eliminar ultimo elemento del stack
void pop(st *s) {
    // Si esta vacio, se muestra un mensaje de error
    if (isempty(s)) {
        cout << "\n STACK EMPTY \n";
    } else {
        // Imprimir el item en la posicion top
        cout << "Item popped= " << s->items[s->top];
        s->top--; // Disminuir el valor de top (top previo deja de ser accesible)
        stack_size--; // Se coloco dentro del else porque sino, disminuia el stack_size aunque estuviera vacia
    }
    cout << endl;
}

void printStack(st *s) {
    cout << "Stack: " << endl; // Antes: printf("Stack: ") pero se utiliza cout actualmente

    // Imprimir el stack desde la posicion 0 hasta stack_size
    for (int i = 0; i < stack_size; i++) {
        cout << s->items[i] << " ";
    }
    cout << endl;
}

// Punto de entrada del programa
int main() {
    int ch; // No se utiliza en el programa

    // Reservacion de memoria dinamica para el stack
    st *s = (st *)malloc(sizeof(st));

    // Inicializar variables del stack
    createEmptyStack(s);

    // Push de valores 1, 2, 3, 4 al stack
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    // Imprimir el stack
    printStack(s);

    // Pop del ultimo elemento
    pop(s);

    // Imprimir stack (sin el 4)
    cout << "\nAfter popping out\n";
    printStack(s);

    // Error: No se libera memoria dinamica -> Colocar delete s;
    delete s;

    return 0;
}
