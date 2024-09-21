/*
Archivo que contiene la definición de la function template processText()
*/

#ifndef TEXTPROCESSOR_HPP
#define TEXTPROCESSOR_HPP

#include <functional>

// Definición de la functionTemplate para processText()
template <typename Container, typename Func>
void processText(Container& container, Func processFunc) {
    // Recibe un Container y una función para procesar
    
    // Recorrido del Container
    for (auto& element : container) {
        processFunc(element); // Ejecutar processFunc callable con element como argumento
    }
}

#endif // TEXTPROCESSOR_HPP
