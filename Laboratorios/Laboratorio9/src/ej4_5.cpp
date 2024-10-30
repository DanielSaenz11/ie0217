#include <iostream>
#include <thread> // Biblioteca para utilizar std::thread
#include <mutex>  // Biblioteca para utilizar std::mutex

int contador = 0;
std::mutex mtx; // Declaración de mutex para contador

// Función que incrementa el valor de la variable global contador
void incrementar() {
    // Loop para incrementar el valor de la variable contador
    for (int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock(mtx); // Protección del acceso a la variable compartida
        contador++; // Aumento del contador
    }
}

int main() {
    // Declaración de dos hilos
    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    // Esperar a que los dos hilos terminen
    hilo1.join();
    hilo2.join();

    // Imprimir el valor final del contador
    std::cout << "Valor final del contador: " << contador << std::endl;
    return 0;
}

