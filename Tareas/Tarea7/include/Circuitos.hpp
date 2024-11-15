

// Circuitos.hpp
#ifndef CIRCUITOS_HPP
#define CIRCUITOS_HPP

#include <vector>

double resistenciaSerie(const std::vector<double>& resistencias);

double resistenciaParalelo(const std::vector<double>& resistencias);

double capacitanciaSerie(const std::vector<double>& capacitancias);

double capacitanciaParalelo(const std::vector<double>& capacitancias);

double inductanciaSerie(const std::vector<double>& inductancias);

double inductanciaParalelo(const std::vector<double>& inductancias);

#endif // CIRCUITOS_HPP
