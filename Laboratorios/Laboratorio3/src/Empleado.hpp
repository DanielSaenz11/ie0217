#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

// Inclusion de librerias
#include <iostream>
#include <string>

using namespace std;

// Declaracion de la clase Empleado
class Empleado {
    // Elementos protegidos
    protected:
        string nombre;
        int id;
        double salario;

    // Elementos publicos
    public:
        /* Firmas de la funciones */
        
        // Constructor de la clase
        Empleado(const string &nombre, int id, double salario);

        // Destructor: Se le dice al compilador que utilice la implementacion predeterminada
        virtual ~Empleado() = default;

        // Metodo para establecer el nombre
        void setNombre(const string &nombre);

        // Metodo que retorna el nombre
        string getNombre() const; // const indica que no se va a modificar las variables propias de la clase

        // Metodo para establecer ID
        void setId(int id);

        // Metodo que retorna ID
        int getId() const;

        // Metodo para establecer el salario
        void setSalario(double salario);

        // Metodo que retorna el salario
        virtual double getSalario() const; // virtual indica que las clases que lo heredan deben sobreescribir el metodo

        // Funcion amiga (permite acceder a los miembros privados): Metodo para comparar los salarios entre dos empleados
        friend bool compararSalario(const Empleado &e1, const Empleado &e2);

        // Sobrecarga de operadores: Modificar el operador <<
        friend ostream &operator<<(ostream &os, const Empleado &empleado);

        // 
        virtual void mostrarInformacion() const = 0; 
        /* const = 0 lo convierte en un metodo virtual puro (no tiene implementacion en
        la clase base)

        Convierte a la clase en una clase abstracta -> Contiene al menos un metodo virtual puro
        No se puede crear un objeto basado en esta clase
         */


};

#endif // EMPLEADO_HPP