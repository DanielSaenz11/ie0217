#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <future>

// Función para calcular la suma parcial de un segmento del vector
int partial_sum(const std::vector<int>& vec, int start, int end) {
    return std::accumulate(vec.begin() + start, vec.begin() + end, 0);
}

int main() {
    const int SIZE = 100000; // Tamaño del vector
    const int NUM_THREADS = 4; // Número de hilos

    // Inicializa el vector con valores del 1 al SIZE
    std::vector<int> vec(SIZE);
    std::iota(vec.begin(), vec.end(), 1);

    // Determina el tamaño de cada segmento
    int segment_size = SIZE / NUM_THREADS;

    // Vector para almacenar los futuros
    std::vector<std::future<int>> futures;

    // Lanza los hilos para calcular las sumas parciales
    for (int i = 0; i < NUM_THREADS; ++i) {
        int start = i * segment_size;
        int end = (i == NUM_THREADS - 1) ? SIZE : start + segment_size;

        futures.push_back(std::async(std::launch::async, partial_sum, std::ref(vec), start, end));
    }

    // Recolecta los resultados de las sumas parciales
    int total_sum = 0;
    for (auto& fut : futures) {
        total_sum += fut.get();
    }

    // Muestra el resultado final
    std::cout << "La suma total es: " << total_sum << std::endl;

    return 0;
}
