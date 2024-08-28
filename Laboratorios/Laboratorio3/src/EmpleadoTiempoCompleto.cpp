#include "EmpleadoTiempoCompleto.hpp"

using namespace std;

// Se utiliza el constructor de la clase Empleado
EmpleadoTiempoCompleto::EmpleadoTiempoCompleto(const string &nombre, int id, 
        double salario, double bonificacion, double deduccion) : Empleado(nombre, id, salario),
        bonificacion(bonificacion), deduccion(deduccion) {}

void EmpleadoTiempoCompleto::setBonificacion(double boni) {
    this->bonificacion = boni; // Modificar el valor de la variable bonificacion
}

void EmpleadoTiempoCompleto::setDeduccion(double dedu) {
    this->deduccion = dedu; // Modificar el valor de la variable deduccion
}

double EmpleadoTiempoCompleto::getSalario() const {
    return salario + bonificacion - deduccion; // Calculo de salario neto
}

void EmpleadoTiempoCompleto::mostrarInformacion() const {
    // *this desempaqueta el contenido del puntero this que apunta a la clase Empleado (imprimir sobreescritura de operador <<)
    cout << *this << ", Bonificacion: " << bonificacion << ", Deduccion: " << deduccion << endl;
}

