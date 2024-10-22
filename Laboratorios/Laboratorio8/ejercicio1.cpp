#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <random>

const int BUFFER_SIZE = 10; // Tamaño del búfer
const int NUM_TASKS = 20;   // Número de tareas a producir

std::queue<int> buffer;      // Búfer compartido
std::mutex mtx;              // Mutex para proteger el acceso al búfer
std::condition_variable cv;  // Variable de condición para la sincronización

int produced_count = 0; // Contador de tareas producidas
int consumed_count = 0; // Contador de tareas consumidas

bool finished = false; // Bandera para indicar si la producción ha terminado

// Función del productor
void producer(int id) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simula tiempo de producción

        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < BUFFER_SIZE; }); // Espera hasta que haya espacio en el búfer

        if (produced_count >= NUM_TASKS) {
            finished = true;
            cv.notify_all(); // Notifica a todos los consumidores para que terminen
            break;
        }

        // Produce una tarea
        int item = produced_count++;
        buffer.push(item);
        std::cout << "Productor " << id << " produjo: " << item << std::endl;

        cv.notify_all(); // Notifica a los consumidores
    }
}

// Función del consumidor
void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty() || finished; }); // Espera hasta que haya algo en el búfer o la producción haya terminado

        if (buffer.empty() && finished) {
            break; // Salir si ya no hay más tareas y la producción ha terminado
        }

        // Consume una tarea
        int item = buffer.front();
        buffer.pop();
        consumed_count++;
        std::cout << "Consumidor " << id << " consumió: " << item << std::endl;

        cv.notify_all(); // Notifica a los productores
        lock.unlock();

        // Simula tiempo de procesamiento
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    // Crea hilos de productores y consumidores
    std::thread producers[2];
    std::thread consumers[2];

    for (int i = 0; i < 2; ++i) {
        producers[i] = std::thread(producer, i + 1);
        consumers[i] = std::thread(consumer, i + 1);
    }

    // Espera a que todos los productores terminen
    for (int i = 0; i < 2; ++i) {
        producers[i].join();
    }

    // Espera a que todos los consumidores terminen
    for (int i = 0; i < 2; ++i) {
        consumers[i].join();
    }

    std::cout << "Producción y consumo finalizados. Total producido: " << produced_count 
              << ", Total consumido: " << consumed_count << std::endl;

    return 0;
}
