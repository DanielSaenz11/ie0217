#include <iostream>
#include <vector> // Estructura de datos para almacenar los empleados

// Incluir header files creados
#include "EmpleadoTiempoCompleto.hpp"
#include "EmpleadoMedioTiempo.hpp"

using namespace std;

int main() {
    // Declaracion del vector de empleados
    vector<Empleado*> empleados;

    // Agregar empleados al vector con la informacion solicitada en el constructor de cada tipo de empleado
    empleados.push_back(new EmpleadoTiempoCompleto("Alice", 1, 50000, 5000, 1000));
    empleados.push_back(new EmpleadoMedioTiempo("Bob", 2, 20, 120));
    empleados.push_back(new EmpleadoTiempoCompleto("Charlie", 3, 55000, 4000, 1500));
    empleados.push_back(new EmpleadoMedioTiempo("David", 4, 25, 100));
    empleados.push_back(new EmpleadoTiempoCompleto("Esteban", 10, 150000, 9000, 60000));

    // Recorrer el vector y mostrar informacion de cada empleado
    for (const auto& empleado : empleados) {
        empleado->mostrarInformacion();
    }

    // Eliminar cada empleado creado para liberar la memoria
    for (const auto& empleado : empleados) {
        delete empleado;
    }

    return 0;
}