/**
 * Codigo de la presentacion
 * Tipos de acceso:
 * 
 * - public: Todas las clases y funciones pueden acceder a los elementos
 * - protected: No se puede acceder fuera de la clase o derivados
 * - private: No se puede acceder del todo (excepcion: funciones y clases amigas)
 */

#include <iostream>
using namespace std;

// Declaracion de clase Animal
class Animal {
    // Elementos publicos
    public:
        // Metodo para cambiar la edad a un valor age
        void setEdad(int age) {
            edad = age;
        }
        // Metodo para obtener la edad (atributo privado)
        int getEdad() {
            return edad;
        }

    // Elemento protegido
    protected:
        string nombre;

    // Elemento privado
    private:
        int edad;
};

// Declaracion de la clase Perro (derivada de Animal)
class Perro : public Animal {
    public:
        // Metodo para cambiar el nombre (protegido)
        void setNombre(string n) {
            nombre = n;
        }
        // Metodo para retornar el nombre
        string getNombre() {
            return nombre;
        }
};


int main() {
    // Declaracion de una instancia de la clase Perro
    Perro miPerro;

    // Uso de metodo setNombre()
    miPerro.setNombre("Toby");

    // Uso de metodo setEdad() -> Heredado
    miPerro.setEdad(3);

    // Imprimir informacion usando los metodos get
    cout << "Mi perro se llama " << miPerro.getNombre() << endl;
    cout << "y tiene " << miPerro.getEdad() << " anios." << endl;

    return 0;
}