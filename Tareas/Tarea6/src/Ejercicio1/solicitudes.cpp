

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
constexpr int TAMANO_BUFFER = 10;
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv_cliente, cv_operador;
std::counting_semaphore<TAMANO_BUFFER> empty_slots(TAMANO_BUFFER);
std::counting_semaphore<TAMANO_BUFFER> full_slots(0);

// Variables de monitoreo
std::atomic<int> total_solicitudes_procesadas{0};
std::atomic<int> tiempo_espera_total_clientes{0};
std::atomic<int> tiempo_espera_total_operadores{0};
std::atomic<bool> produccion_finalizada{false};

// Generador de tiempos aleatorios para simular tiempos de espera
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(50, 150);