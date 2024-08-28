#include "Empleado.hpp"

using namespace std;

// Asignacion de los parametros del constructor con sintaxis :
Empleado::Empleado(const string &nombre, int id, double salario) : nombre(nombre), id(id), salario(salario) {}

void Empleado::setNombre(const string &nombre) {
    this->nombre = nombre; // cambiar atributo nombre al pasado como parametro
}

string Empleado::getNombre() const {
    return nombre; // retornar nombre
}

void Empleado::setId(int id) {
    this->id = id; // cambiar atributo id al pasado como parametro
}

int Empleado::getId() const {
    return id; // retornar id
}

void Empleado::setSalario(double salario) {
    this->salario = salario; // cambiar atributo salario al pasado como parametro
}

double Empleado::getSalario() const {
    return salario; // retornar salario
}

bool compararSalario(const Empleado &e1, const Empleado &e2) {
    return e1.salario > e2.salario; // comparacion entre el valor de los enteros
}

ostream &operator<<(ostream &os, const Empleado &empleado) {
    // Modificar el operador << para Empleado
    os << "Nombre: " << empleado.nombre << ", ID: " << empleado.id << ", Salario: " << empleado.salario;
    return os; // retornar modificacion
}


