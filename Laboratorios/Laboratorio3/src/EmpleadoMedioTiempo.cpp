#include "EmpleadoMedioTiempo.hpp"

using namespace std;

// Constructor de la clase EmpleadoMedioTiempo con uso de sintaxis : para asignar parametros
EmpleadoMedioTiempo::EmpleadoMedioTiempo(const string &nombre, int id, int
horasTrabajadas, double tarifaPorHora) : Empleado(nombre, id, tarifaPorHora * horasTrabajadas),
horasTrabajadas(horasTrabajadas), tarifaPorHora(tarifaPorHora) {}

void EmpleadoMedioTiempo::setHorasTrabajadas(int horas) {
    this->horasTrabajadas = horas; // Modificar el valor de variable horasTrabajadas
}

void EmpleadoMedioTiempo::setTarifaPorHora(double tarifa) {
    this->tarifaPorHora = tarifa; // Modificar el valor de la variable tarifaPorHora
}

double EmpleadoMedioTiempo::getSalario() const {
    return tarifaPorHora * horasTrabajadas; // Calculo de salario
}

/* Sobreescritura de metodo mostrarInformacion() utilizando la sobrecarga de operadores
    para Empleado y ampliando para esta clase
 */
void EmpleadoMedioTiempo::mostrarInformacion() const {
    cout << *this << ", Horas Trabajadas: " << horasTrabajadas << ", Tarifa por Hora: " <<
    tarifaPorHora << endl;
}