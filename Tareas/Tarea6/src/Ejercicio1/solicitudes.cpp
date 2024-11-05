

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
std::counting_semaphore<TAMANO_BUFFER> empty_slots(TAMANO_BUFFER); // Semáforo empty_slots: Tamaño inicial del buffer
std::counting_semaphore<TAMANO_BUFFER> full_slots(0); // Semáforo full_slots: Tamaño inicial de 0

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
    // Generar solicitudes por cliente
    for (int i = 0; i < num_solicitudes; ++i) {
        int solicitud = id * 100 + i; // Generación de la solicitud a partir del ID del cliente

        // Inicio de cronómetro para medir tiempo de espera
        auto inicio = std::chrono::high_resolution_clock::now();
        
        // Espacio disponible en buffer: Decrementa el valor del contador del semáforo empty_slots
        empty_slots.acquire();

        // Fin de cronómetro para medir tiempo de espera
        auto fin = std::chrono::high_resolution_clock::now();

        // Cálculo del tiempo de espera para el cliente
        tiempo_espera_total_clientes += std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

        // Bloque de código que bloquea el lock: Crea un scope
        {
            std::lock_guard<std::mutex> lock(mtx); // Bloquear porción de memoria compartida
            buffer.push(solicitud); // Realizar la solicitud
            cout << "Cliente " << id << " generó la solicitud " << solicitud << endl;
            // Desbloquear lock al salir del scope
        }

        // Incrementa el valor del contador de full_slots: Hay una nueva solicitud
        full_slots.release();

        // Notificar a un operador en espera de una solicitud en el buffer
        cv_operador.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen))); // Espera aleatoria entre solicitudes
    }

    // Indicar que todos los clientes terminaron de generar solicitudes
    produccion_finalizada = true;
    
    // Notifica a todos los hilos de operadores en espera
    cv_operador.notify_all();
}

// Función para los hilos de los operadores (consumidores)
void operador(int id) {
    // Bucle infinito que consume tareas
    while (true) {
        // Decrementa el valor del contador full_slots: Se consumió una solicitud
        full_slots.acquire();

        // Bloqueo exclusivo sobre mtx para que únicamente un hilo pueda acceder
        std::unique_lock<std::mutex> lock(mtx);

        // Hilo del operador en espera mientras no se cumple la condición en la función lambda
        // Permite que otros hilos accedan al buffer durante la espera
        cv_operador.wait(lock, [] { return !buffer.empty() || produccion_finalizada; });

        if (buffer.empty() && produccion_finalizada) break; // Terminar si no hay más solicitudes

        int solicitud = buffer.front(); // Obtener el elemento del frente de la cola
        buffer.pop(); // Elimina el elemento sacado previamente
        total_solicitudes_procesadas++; // Aumenta el número de solicitudes procesadas
        cout << "Operador " << id << " procesó la solicitud " << solicitud << endl;

        lock.unlock(); // Desbloquea el lock
        empty_slots.release(); // Incrementa el contador de espacios libres en el buffer
        
        // Notificar a un cliente en espera de un espacio en el buffer
        cv_cliente.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Tiempo de procesamiento simulado
    }
}

// Monitoreo de rendimiento y métricas
void monitorear_rendimiento(int num_clientes, int num_operadores) {
    // Cálculo de tiempo de espera promedio entre clientes
    int espera_promedio_clientes = tiempo_espera_total_clientes / (num_clientes * TAMANO_BUFFER);

    // Cálculo de tiempo de espera promedio entre operadores
    int espera_promedio_operadores = tiempo_espera_total_operadores / (num_operadores * TAMANO_BUFFER);
    
    // Imprimir resultados
    cout << "\n--- Métricas de Rendimiento ---" << endl;
    cout << "Total de solicitudes procesadas: " << total_solicitudes_procesadas << endl;
    cout << "Tiempo de espera promedio para clientes: " << espera_promedio_clientes << " ms" << endl;
    cout << "Tiempo de espera promedio para operadores: " << espera_promedio_operadores << " ms" << endl;
    cout << "Tamaño del buffer: " << TAMANO_BUFFER << endl;
}

int main() {
    int num_clientes = 4;
    int num_operadores = 3;
    int num_solicitudes_por_cliente = 10;

    vector<thread> clientes, operadores;

    // Crear hilos de clientes
    for (int i = 0; i < num_clientes; ++i) {
        clientes.emplace_back(cliente, i, num_solicitudes_por_cliente);
    }

    // Crear hilos de operadores
    for (int i = 0; i < num_operadores; ++i) {
        operadores.emplace_back(operador, i);
    }

    // Esperar a que terminen todos los clientes
    for (auto& hilo_cliente : clientes) {
        hilo_cliente.join();
    }

    // Esperar a que terminen todos los operadores
    for (auto& hilo_operador : operadores) {
        hilo_operador.join();
    }

    monitorear_rendimiento(num_clientes, num_operadores);
    cout << "Todos los clientes y operadores han terminado.\n";

    return 0;
}