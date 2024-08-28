/**
 * Archivo donde se definen las funciones del header file persona.hpp
 */

#include "persona.hpp"
using namespace std;

/**
 * @brief Constructor de la clase Persona
 * 
 * Recibe el nombre de la Persona y la edad
 *
 * @param nombre String
 * @param edad integer
 * @return void
 */
Persona::Persona(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

/**
 * @brief Método que retorna el nombre del objeto Persona
 * 
 * @param None
 * @return string nombre
 */
string Persona::getNombre() {
    return nombre;
}

/**
 * @brief Método que retorna el nombre del objeto Persona
 * 
 * @param None
 * @return int edad
 */
int Persona::getEdad() {
    return edad;
}

/**
 * @brief Método para cambiar el valor de la variable edad
 * 
 * @param edad integer
 * @return void
 */
void Persona::setEdad(int edad) {
    this->edad = edad;
}