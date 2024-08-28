#ifndef EMPLEADO_MEDIO_TIEMPO_HPP
#define EMPLEADO_MEDIO_TIEMPO_HPP

#include "Empleado.hpp"

using namespace std;

class EmpleadoMedioTiempo : public Empleado {
    // Miembros privados de la clase
    private:
        int horasTrabajadas;
        double tarifaPorHora;
    
    public:
        // Contructor de la clase EmpleadoMedioTiempo
        EmpleadoMedioTiempo(const string &nombre, int id, int horasTrabajadas, double tarifaPorHora);

        // Metodo para establecer las horasTrabajadas
        void setHorasTrabajadas(int horas);

        // Metodo para establecer tarifaPorHora
        void setTarifaPorHora(double tarifa);

        // Metodo que retorna el calculo del salario del EmpleadoMedioTiempo
        double getSalario() const override;

        // Metodo para mostrar la informacion del objeto sobreescrito de Empleado
        void mostrarInformacion() const override;
};

#endif // EMPLEADO_MEDIO_TIEMPO_HPP