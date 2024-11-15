/**
 * @file Circuitos.cpp
 * @brief Implementación de las funciones para cálculos eléctricos de circuitos.
 * @details Este archivo contiene las implementaciones de funciones para calcular resistencias,
 * capacitancias e inductancias en configuraciones de serie y paralelo, junto con la función 
 * principal para combinar ambas configuraciones en el cálculo de capacitancia equivalente.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 15/11/2024
 */

#include "Circuitos.hpp"
#include <stdexcept>
#include <numeric>

// Función para calcular la resistencia equivalente en serie
double resistenciaSerie(const std::vector<double>& resistencias) {
    // Verificar que vector del parámetro no esté vacío
    if (resistencias.empty()) {
        throw std::invalid_argument("Error: Lista de resistencias vacía.");
    }

    // Verificar que todos los valores son válidos (mayores que cero)
    for (const auto& r : resistencias) {
        if (r <= 0) {
            throw std::invalid_argument("Error: Todos los valores de resistencia deben ser mayores que cero.");
        }
    }

    // Sumar todos los valores de resistencias del vector: R_1 + R_2 + R_3 + ...
    double resultado =  std::accumulate(resistencias.begin(), resistencias.end(), 0.0);
    return resultado;
}

// Función para calcular la resistencia equivalente en paralelo
double resistenciaParalelo(const std::vector<double>& resistencias) {
    // Verificar que vector del parámetro no esté vacío
    if (resistencias.empty()) {
        throw std::invalid_argument("Error: Lista de resistencias vacía.");
    }

    // 1 / (1/R_1 + 1/R_2 + 1/R_3 + ...)
    double inversaTotal = 0.0;
    for (double r : resistencias) {
        if (r <= 0) throw std::invalid_argument("Error: La resistencia debe ser mayor que cero.");
        
        // Agregar inversa de cada resistencia a la inversa total
        inversaTotal += 1.0 / r;
    }

    // Calcular la inversa de la inversa total
    return 1.0 / inversaTotal;
}

// Función para calcular la capacitancia equivalente en serie
double capacitanciaSerie(const std::vector<double>& capacitancias) {
    // Verificar que vector del parámetro no esté vacío
    if (capacitancias.empty()) {
        throw std::invalid_argument("Error: Lista de capacitancias vacía.");
    }

    // 1 / (1/C_1 + 1/C_2 + 1/C_3 + ...)
    double inversaTotal = 0.0;
    for (double c : capacitancias) {
        if (c <= 0) throw std::invalid_argument("Error: La capacitancia debe ser mayor que cero.");
        inversaTotal += 1.0 / c;
    }

    // Calcular la inversa de la inversa total
    return 1.0 / inversaTotal;
}

// Función para calcular la capacitancia equivalente en paralelo
double capacitanciaParalelo(const std::vector<double>& capacitancias) {
    // Verificar que vector del parámetro no esté vacío
    if (capacitancias.empty()) {
        throw std::invalid_argument("Error: Lista de capacitancias vacía.");
    }

    // Verificar que todos los valores son válidos (mayores que cero)
    for (const auto& c : capacitancias) {
        if (c <= 0) {
            throw std::invalid_argument("Error: Todos los valores de capacitancia deben ser mayores que cero.");
        }
    }

    // Sumar todos los valores de capacitancias del vector
    double resultado = std::accumulate(capacitancias.begin(), capacitancias.end(), 0.0);
    return resultado;
}

// Función para calcular la inductancia equivalente en serie
double inductanciaSerie(const std::vector<double>& inductancias) {
    // Verificar que vector del parámetro no esté vacío
    if (inductancias.empty()) {
        throw std::invalid_argument("Error: Lista de inductancias vacía.");
    }

    // Verificar que todos los valores son válidos (mayores que cero)
    for (const auto& l : inductancias) {
        if (l <= 0) {
            throw std::invalid_argument("Error: Todos los valores de inductancia deben ser mayores que cero.");
        }
    }

    // Sumar todos los valores de inductancias del vector
    double resultado = std::accumulate(inductancias.begin(), inductancias.end(), 0.0);
    return resultado;
}

// Función para calcular la inductancia equivalente en paralelo
double inductanciaParalelo(const std::vector<double>& inductancias) {
    // Verificar que vector del parámetro no esté vacío
    if (inductancias.empty()) {
        throw std::invalid_argument("Error: Lista de inductancias vacía.");
    }

    // 1 / (1/L_1 + 1/L_2 + 1/L_3 + ...)
    double inversaTotal = 0.0;
    for (double l : inductancias) {
        if (l <= 0) throw std::invalid_argument("Error: La inductancia debe ser mayor que cero.");
        inversaTotal += 1.0 / l;
    }

    // Calcular la inversa de la inversa total
    return 1.0 / inversaTotal;
}

double capacitanciaEquivalenteSerieParalelo(const std::vector<std::vector<double>>& gruposCapacitancias) {
    // Verificar que vector del parámetro no esté vacío
    if (gruposCapacitancias.empty()) {
        throw std::invalid_argument("Error: No se proporcionaron grupos de capacitancias.");
    }

    // Vector para almacenar resultados de capacitancias en paralelo
    std::vector<double> resultadosParalelo;

    // Procesar cada grupo y calcular su capacitancia equivalente en paralelo
    for (const auto& grupo : gruposCapacitancias) {
        resultadosParalelo.push_back(capacitanciaParalelo(grupo));
    }

    // Combinar todas las capacitancias equivalentes en paralelo como una configuración en serie
    return capacitanciaSerie(resultadosParalelo);
}