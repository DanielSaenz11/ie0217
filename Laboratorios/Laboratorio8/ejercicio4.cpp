#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Dos mutex globales
std::mutex mutex1;
std::mutex mutex2;

// Función que simula un deadlock
void cause_deadlock(int id) {
    if (id == 1) {
        // El hilo 1 intenta bloquear mutex1 y luego mutex2
        std::lock_guard<std::mutex> lock1(mutex1);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simula trabajo
        std::lock_guard<std::mutex> lock2(mutex2);
        std::cout << "Hilo 1 completado" << std::endl;
    } else {
        // El hilo 2 intenta bloquear mutex2 y luego mutex1
        std::lock_guard<std::mutex> lock2(mutex2);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simula trabajo
        std::lock_guard<std::mutex> lock1(mutex1);
        std::cout << "Hilo 2 completado" << std::endl;
    }
}

// Función que resuelve el deadlock utilizando std::lock
void avoid_deadlock(int id) {
    // Bloquea ambos mutexes de manera consistente
    std::lock(mutex1, mutex2);

    // Usa lock_guard con std::adopt_lock para indicar que los mutexes ya están bloqueados
    std::lock_guard<std::mutex> lock1(mutex1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mutex2, std::adopt_lock);

    std::cout << "Hilo " << id << " completado sin deadlock" << std::endl;
}

int main() {
    // Ejemplo 1: Causa un deadlock
    std::cout << "Ejecutando con deadlock..." << std::endl;
    std::thread t1(cause_deadlock, 1);
    std::thread t2(cause_deadlock, 2);

    t1.join();
    t2.join();

    // Ejemplo 2: Evita el deadlock
    std::cout << "Ejecutando sin deadlock..." << std::endl;
    std::thread t3(avoid_deadlock, 1);
    std::thread t4(avoid_deadlock, 2);

    t3.join();
    t4.join();

    return 0;
}
