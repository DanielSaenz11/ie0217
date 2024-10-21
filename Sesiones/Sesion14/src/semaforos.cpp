#include <iostream>
#include <semaphore> // Biblioteca para uso de semáforos

// Semáforo binario (similar a un mutex)
std::counting_semaphore<1> sem(1); // Si se coloca otro número, permite que esa cantidad de hilos accedan al espacio

// Función para acceder a recurso compartido
void accessResource() {
    sem.acquire(); // Decrementa el contador y bloquea si el contador es cero
    // Sección crítica
    sem.release(); // Incrementa el contador y desbloquea a un hilo

}