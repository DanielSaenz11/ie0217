#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <barrier>

// Mutex para proteger la salida en la consola
std::mutex console_mutex;

// Barrera para sincronizar las tareas
std::barrier sync_point(3);

// Función que simula una tarea del sistema
void perform_task(int id) {
    {
        // Bloqueo para asegurar que la salida no se mezcle
        std::lock_guard<std::mutex> lock(console_mutex);
        std::cout << "Tarea " << id << " está realizando trabajo inicial...\n";
    }

    // Simula trabajo con un retardo
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));

    {
        // Bloqueo para asegurar que la salida no se mezcle
        std::lock_guard<std::mutex> lock(console_mutex);
        std::cout << "Tarea " << id << " alcanzó el punto de sincronización.\n";
    }

    // Sincronización en la barrera
    sync_point.arrive_and_wait();

    {
        // Bloqueo para asegurar que la salida no se mezcle
        std::lock_guard<std::mutex> lock(console_mutex);
        std::cout << "Tarea " << id << " continúa con el trabajo final.\n";
    }

    // Simula trabajo adicional con un retardo
    std::this_thread::sleep_for(std::chrono::milliseconds(50 * id));

    {
        // Bloqueo para asegurar que la salida no se mezcle
        std::lock_guard<std::mutex> lock(console_mutex);
        std::cout << "Tarea " << id << " ha completado el trabajo.\n";
    }
}

int main() {
    const int NUM_TASKS = 3; // Número de tareas a ejecutar

    // Crea y lanza los hilos para ejecutar las tareas
    std::vector<std::thread> threads;
    for (int i = 1; i <= NUM_TASKS; ++i) {
        threads.push_back(std::thread(perform_task, i));
    }

    // Espera a que todas las tareas terminen
    for (auto& th : threads) {
        th.join();
    }

    std::cout << "Todas las tareas han completado su ejecución.\n";

    return 0;
}
