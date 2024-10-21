/*
Ejemplos de race conditions en memoria compartida
*/

#include <iostream>

int main() {

    /*
    Si múltiples hilos ejecutan este bucle simultáneamente, pueden leerel mismo valor
    de counter antes de que se actualice, resultando en un conteo incorrecto.
    */
    int counter = 0;
    for (int i = 0; i < 1000; ++i) {
        ++counter; // Incremento no atómico
    }

    std::vector<int> myList;

    // Ambos hilos intentan acceder al mismo espacio de memoria compartida al mismo tiempo
    // Si no se sincronizan, pueden corromper la estructura interna de myList

    // Hilo 1
    myList.push_back(1);

    // Hilo 2
    myList.push_back(2);

    return 0;
}