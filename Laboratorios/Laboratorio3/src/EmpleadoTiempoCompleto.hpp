#ifndef EMPLEADO_TIEMPO_COMPLETO_HPP
#define EMPLEADO_TIEMPO_COMPLETO_HPP

#include "Empleado.hpp"

using namespace std;

class EmpleadoTiempoCompleto : public Empleado {
    private: 
        // Atributos privados
        double bonificacion;
        double deduccion;

    public:
        // Se heredan los atributos de Empleado
        EmpleadoTiempoCompleto(const string &nombre, int id, 
        double salario, double bonificacion, double deduccion);

        // Metodo para establecer la bonificacion del objeto Empleado
        void setBonificacion(double bonificacion);

        // Metodo para establecer la deduccion del objeto Empleado
        void setDeduccion(double deduccion);

        // Class Empleado era metodo virtual: retorna el salario
        double getSalario() const override; // override = sobreescribir

        // Mostrar la informacion del EmpleadoTiempoCompleto
        void mostrarInformacion() const override; // override = sobreescribir

};

#endif // EMPLEADO_TIEMPO_COMPLETO_HPP