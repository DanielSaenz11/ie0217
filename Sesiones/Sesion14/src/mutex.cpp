#include <iostream>
#include <mutex> // Biblioteca para uso de mutex

std::mutex mtx; // Declaración de mutex

// Función que realiza un incremento seguro para un contador en memoria compartida
void safeIncrement(int &counter) {
    std::lock_guard<std::mutex> lock(mtx);
    ++counter; // Ningún otro hilo modifica el contador

    // mtx se libera automáticamente cuando lock sale del ámbito
}
