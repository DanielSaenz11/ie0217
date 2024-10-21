#include <iostream>
#include <barrier>

std::barrier sync_point(5); // Barrera para 5 hilos

void threadFunction() {
    // Realizar tareas antes de la barrera
    sync_point.arrive_and_wait(); // Esperar a que todos los hilos lleguen aquí
    // Continuar después de que todos los hilos se hayan sincronizado
}