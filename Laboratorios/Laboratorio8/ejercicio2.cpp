#include <iostream>
#include <thread> // Manejar hilos en C++
#include <vector>
#include <mutex> // Mutex -> protección de recursos compartidos

/* 
Si se reduce la cantidad de hilos y el número de incrementos, hay menos concurrencias y cada hilo tiene
más tiempo para acceder al contador
*/ 
const int NUM_THREADS = 100;  // Número de hilos que se crean para cada función
const int NUM_INCREMENTS = 10000;  // Número de incrementos por hilo

int counter = 0;  // Contador compartido por los hilos
std::mutex mtx;   // Mutex para proteger el acceso al contador

// Función que incrementa el contador sin protección
void increment_without_lock() {
    for (int i = 0; i < NUM_INCREMENTS; ++i) {
        counter++; // Distintos hilos pueden acceder a counter a la vez, sin que su valor se actualice correctamente
    }
}

// Función que incrementa el contador con protección de mutex
void increment_with_lock() {
    for (int i = 0; i < NUM_INCREMENTS; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Protección de la sección crítica
        counter++; // Counter protegido (un hilo accede a la variable por vez)
        // Lock guard libera el mutex al salir del ámbito de la función
    }
}

// Función main(): Punto de inicio del programa
int main() {
    // Ejemplo 1: Incremento sin protección (condición de carrera)
    counter = 0; // Variable contador
    std::vector<std::thread> threads; // Vector que contiene los hilos del programa

    // Se crean NUM_THREADS hilos sin la protección al aumentar contador
    for (int i = 0; i < NUM_THREADS; ++i) {
        // Añade un hilo que corresponde a la función increment_without_lock a threads
        threads.push_back(std::thread(increment_without_lock));
    }

    // Se recorre por cada hilo del vector threads
    for (auto& th : threads) {
        th.join(); // Espera a que el hilo th termine
    }

    // Valor del contador sin la protección con mutex
    std::cout << "Resultado sin protección: " << counter << std::endl;

    // Ejemplo 2: Incremento con protección (uso de mutex)
    counter = 0; // Reiniciar valor de counter a 0
    threads.clear(); // Limpiar el vector de hilos

    // Se crean NUM_THREADS hilos con la protección al aumentar contador
    for (int i = 0; i < NUM_THREADS; ++i) {
        // Añade un hilo que corresponde a la función increment_with_lock a threads
        threads.push_back(std::thread(increment_with_lock));
    }

    // ESe recorre por cada hilo del vector threads
    for (auto& th : threads) {
        th.join(); // Espera a que el hilo th termine
    }

    // Imprime el resultado del contador con la protección de mutex (resultado correcto)
    std::cout << "Resultado con protección: " << counter << std::endl;

    return 0;
}
