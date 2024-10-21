#include <iostream>
#include <mutex>
#include <condition_variable>

std::mutex mtx; // Declaración de mutex
std::condition_variable cv; // Declaración de condition_variable
bool ready = false; // Declaración de variable para notificar

// Función que pone hilo en espera
void waitingThread() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{return ready; }); // Espera hasta que ready sea true
    // Continuar ejecución
}

// Función que notifica a un hilo que se cumplió la condición
void notifyingThread() {
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    cv.notify_one(); // Notifica a uno de los hilos en espera
}
