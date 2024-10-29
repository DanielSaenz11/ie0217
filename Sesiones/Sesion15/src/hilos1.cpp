/*
Programa para probar el funcionamiento de la herramienta de debugging TSan (ThreadSanitizer) y Helgrind
para detectar condiciones de carrera
*/

#include <iostream>
#include <thread>

int counter = 0; // Variable global de contador (sobre ella ocurren las condiciones de carrera)

// Función para incrementar el valorr de la variable global contador
void increment() {
    for (int i = 0; i < 100000; ++i) {
        ++counter; // Condición de carrera
    }
}

int main() {
    // Inicializar los threads
    std::thread t1(increment);
    std::thread t2(increment);

    // Esperar a que ambos threads terminen su ejecución
    t1.join();
    t2.join();

    // Imprimir el valor final del contador
    std::cout << "Counter: " << counter << std::endl;

    return 0;
}