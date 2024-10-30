#include <iostream>
#include <thread>

int contador = 0;

void incrementar() {
    for (int i = 0; i < 10000; i++) {
        contador++;
    }
}

int main() {
    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();

    std::cout << "Valor final del contador: " << contador << std::endl;
    return 0;
}


// g++ -g -fsanitize=thread -o thread_race thread_race.cpp -pthread
// ./thread_race