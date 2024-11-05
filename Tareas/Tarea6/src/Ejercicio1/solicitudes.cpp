

#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <semaphore>
#include <chrono>
#include <atomic>
#include <random>

using namespace std;

// Configuración inicial
constexpr int TAMANO_BUFFER = 10; // Tamaño del buffer
std::queue<int> buffer; // Buffer modelado como una cola
std::mutex mtx; // Mutex para proteger el acceso al buffer
std::condition_variable cv_cliente, cv_operador; // Variables de condición para cliente y operador
std::counting_semaphore<TAMANO_BUFFER> empty_slots(TAMANO_BUFFER); // Semáforo empty_slots
std::counting_semaphore<TAMANO_BUFFER> full_slots(0); // Semáforo full_slots

// Variables de monitoreo
std::atomic<int> total_solicitudes_procesadas{0}; // Total de solicitudes procesadas
std::atomic<int> tiempo_espera_total_clientes{0}; // Tiempo de espera total de clientes
std::atomic<int> tiempo_espera_total_operadores{0}; // Tiempo de espera total de operadores
std::atomic<bool> produccion_finalizada{false}; // Booleano para indicar si la producción finalizó

// Generador de tiempos aleatorios para simular tiempos de espera
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(50, 150);


// Función para los hilos de los clientes (productores)
void cliente(int id, int num_solicitudes) {
    for (int i = 0; i < num_solicitudes; ++i) {
        int solicitud = id * 100 + i; // Generación de la solicitud


        auto inicio = std::chrono::high_resolution_clock::now();
        empty_slots.acquire();
        auto fin = std::chrono::high_resolution_clock::now();
        tiempo_espera_total_clientes += std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(solicitud);
            cout << "Cliente " << id << " generó la solicitud " << solicitud << endl;
        }

        full_slots.release();
        cv_operador.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen))); // Espera aleatoria entre solicitudes
    }

    // Indicar que todos los clientes terminaron de generar solicitudes
    produccion_finalizada = true;
    cv_operador.notify_all();
}

// Función para los hilos de los operadores (consumidores)
void operador(int id) {
    while (true) {
        full_slots.acquire();

        std::unique_lock<std::mutex> lock(mtx);
        cv_operador.wait(lock, [] { return !buffer.empty() || produccion_finalizada; });

        if (buffer.empty() && produccion_finalizada) break; // Terminar si no hay más solicitudes

        int solicitud = buffer.front();
        buffer.pop();
        total_solicitudes_procesadas++;
        cout << "Operador " << id << " procesó la solicitud " << solicitud << endl;

        lock.unlock();
        empty_slots.release();
        cv_cliente.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Tiempo de procesamiento simulado
    }
}

