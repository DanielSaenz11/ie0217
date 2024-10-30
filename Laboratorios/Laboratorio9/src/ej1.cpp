#include <iostream>
#include <vector>
#include <algorithm>

// Función que calcula la media aritmética de un vector de elementos
double calcularMedia(const std::vector<int>& numeros) {
    double suma = 0.0; // Se colocó como tipo de dato double a la suma

    // Se ajustaron los límites del for para que únicamente llegue al último elemento. Anteriormente se obtenía un comportamiento indefinido
    for (int i = 0; i < numeros.size(); i++) {
        suma += numeros[i]; // Suma de cada uno de los elementos del vector
    }
    return suma / numeros.size(); // Retornar media (suma_total / total_elementos)
}

// Función que calcula la mediana de un vector
double calcularMediana(std::vector<int> numeros) {
    std::sort(numeros.begin(), numeros.end()); // Ordena el vector

    int tam = numeros.size(); // Variable que contiene el tamaño del vector
    if (tam % 2 == 0) {
        // En caso de ser par, se retorna el promedio entre sus dos elementos en el medio
        return (numeros[tam/2 - 1] + numeros[tam/2]) / 2.0; // Se colocó 2.0 para que al hacer la división, se retorne un valor con decimales
    } else {
        // Si el tamaño es impar, se retorna el elemento medio
        return numeros[tam/2];
    }
}

int main() {
    // Declaración de vector
    std::vector<int> numeros = {1, 4, 8, 110, 33, 49};

    double media = calcularMedia(numeros);
    double mediana = calcularMediana(numeros);

    // std::cout << "Media: " << media << std::endl;
    std::cout << "Mediana: " << mediana << std::endl;

    return 0;
}
