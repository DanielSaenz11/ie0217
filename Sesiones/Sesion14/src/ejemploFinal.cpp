#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <semaphore>
#include <chrono> // Medición de tiempos

using namespace std;

constexpr int BUFFER_SIZE = 10; // Tamaño del buffer compartido
std::queue<int> buffer; // Cola que actúa como buffer compartido
std::mutex mtx; // Protege el acceso al buffer
std::condition_variable cv_producer, cv_consumer; // Variables de condición para notificar a los productores y consumidores

// Semáforos que controlan el número de slots vacíos y llenos en el buffer
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE); // Inicializado con BUFFER_SIZE
std::counting_semaphore<BUFFER_SIZE> full_slots(0); // Inicializado con 0

// Función del productor
void producer(int id, int num_tasks) {
    // Producción de tareas
    for (int i = 0; i < num_tasks; ++i) {
        // Produce un item
        int item = id * 100 + i;

        // Espera a que haya un slot vacío
        empty_slots.acquire(); // Decrementa el contador de slots vacíos

        // Sección crítica: Agrega la tarea al buffer
        {
            std::lock_guard<std::mutex> lock(mtx); // Protección del acceso al buffer
            buffer.push(item); // Agregar el item
            std::cout << "Producer " << id << " produced item " << item << std::endl;
        }

        full_slots.release(); // Incrementa el contador de slots llenos
        cv_consumer.notify_one(); // Notifica a un consumidor
    }
}

// Función del consumidor
void consumer (int id) {
    // Bucle infinito que consume tareas
    while (true) {
        full_slots.acquire(); // Decrementa el contador de slots llenos
        std::unique_lock<std::mutex> lock(mtx);

        // Espera hasta que haya un item en el buffer
        cv_consumer.wait(lock, []{ return !buffer.empty(); });

        // Sección crítica
        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumer " << id << " consumed items " << item << std::endl;

        lock.unlock(); // Libera el lock
        empty_slots.release(); // Incrementa el contador de slots vacíos
        cv_producer.notify_one(); // Notifica a un productor

        // Simular tiempo de procesamiento
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    // Definición de número de productores y consumidores
    const int num_producers = 2;
    const int num_consumers = 3;
    const int num_tasks_per_producer = 10;

    // Creación de threads
    std::vector<std::thread> producers, consumers;

    // Crear un hilo para el producer
    for (int i = 0; i < num_producers; ++i) {
        producers.emplace_back(producer, i, num_tasks_per_producer);
    }

    // Crear un hilo de consumidores
    for (int i = 0; i < num_consumers; ++i) {
        consumers.emplace_back(consumer, i);
    }

    // Unir hilos de producer: Esperar a que terminen
    for (auto& producer_thread : producers) {
        producer_thread.join();
    }

    // Permitir a los consumidores terminar el proceso
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Idealmente se indica a los consumidores que se detengan, pero se va a salir (exit) por simplificidad
    std::cout << "All producers have finished." << std::endl;
    
    return 0;
}
