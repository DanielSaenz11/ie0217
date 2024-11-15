/**
 * @file Circuitos.hpp
 * @brief Declaraciones de funciones para cálculos eléctricos de circuitos.
 * @details Este archivo contiene las declaraciones de funciones auxiliares y principales
 * para calcular resistencias, capacitancias e inductancias en configuraciones de serie y paralelo.
 * También incluye una función para calcular la capacitancia equivalente combinando ambas configuraciones, 
 * la cual fue realizada a partir de Test-Driven Development.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @copyright MIT License
 * @date 15/11/2024
 */


#ifndef CIRCUITOS_HPP
#define CIRCUITOS_HPP

#include <vector>

/**
 * @brief Calcula la resistencia equivalente en serie.
 * @details Suma todos los valores del vector de resistencias para obtener la resistencia equivalente.
 * 
 * @param resistencias Vector con los valores de las resistencias (en Ohms).
 * @return `double` La resistencia equivalente en serie (en Ohms).
 * @throws `std::invalid_argument` Si el vector está vacío o contiene valores negativos.
 */
double resistenciaSerie(const std::vector<double>& resistencias);


/**
 * @brief Calcula la resistencia equivalente en paralelo.
 * @details Calcula la resistencia equivalente en paralelo mediante la suma de los inversos
 * de las resistencias individuales.
 * 
 * @param resistencias Vector con los valores de las resistencias (en Ohms).
 * @return `double` La resistencia equivalente en paralelo (en Ohms).
 * @throws `std::invalid_argument` Si el vector está vacío o contiene valores negativos.
 */
double resistenciaParalelo(const std::vector<double>& resistencias);

/**
 * @brief Calcula la capacitancia equivalente en serie.
 * @details Calcula la capacitancia equivalente en serie mediante la suma de los inversos
 * de las capacitancias individuales.
 * 
 * @param capacitancias Vector con los valores de las capacitancias (en Faradios).
 * @return `double` La capacitancia equivalente en serie (en Faradios).
 * @throws `std::invalid_argument` Si el vector está vacío o contiene valores negativos.
 */
double capacitanciaSerie(const std::vector<double>& capacitancias);

/**
 * @brief Calcula la capacitancia equivalente en paralelo.
 * @details Suma todos los valores del vector de capacitancias para obtener la capacitancia equivalente.
 * 
 * @param capacitancias Vector con los valores de las capacitancias (en Faradios).
 * @return `double` La capacitancia equivalente en paralelo (en Faradios).
 * @throws `std::invalid_argument` Si el vector está vacío o contiene valores negativos.
 */
double capacitanciaParalelo(const std::vector<double>& capacitancias);

/**
 * @brief Calcula la inductancia equivalente en serie.
 * @details Suma todos los valores del vector de inductancias para obtener la inductancia equivalente.
 * 
 * @param inductancias Vector con los valores de las inductancias (en Henrios).
 * @return `double` La inductancia equivalente en serie (en Henrios).
 * @throws `std::invalid_argument` Si el vector está vacío o contiene valores negativos.
 */
double inductanciaSerie(const std::vector<double>& inductancias);

/**
 * @brief Calcula la inductancia equivalente en paralelo.
 * @details Calcula la inductancia equivalente en paralelo mediante la suma de los inversos
 * de las inductancias individuales.
 * 
 * @param inductancias Vector con los valores de las inductancias (en Henrios).
 * @return `double` La inductancia equivalente en paralelo (en Henrios).
 * @throws `std::invalid_argument` Si el vector está vacío o contiene valores negativos.
 */
double inductanciaParalelo(const std::vector<double>& inductancias);

/**
 * @brief Calcula la capacitancia equivalente combinando serie y paralelo.
 * @details Procesa un vector de vectores donde cada subvector representa un grupo de capacitancias
 * conectadas en paralelo. Calcula primero las equivalentes en paralelo y luego combina los resultados en serie.
 * 
 * @param gruposCapacitancias Vector de vectores, donde cada subvector representa capacitancias en paralelo (en Faradios).
 * @return `double` La capacitancia equivalente combinada (en Faradios).
 * @throws `std::invalid_argument` Si algún subvector está vacío, contiene valores negativos, o si no se proporciona ningún grupo.
 */
double capacitanciaEquivalenteSerieParalelo(const std::vector<std::vector<double>>& gruposCapacitancias);

#endif // CIRCUITOS_HPP
