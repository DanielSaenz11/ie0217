/**
 * Codigo de la presentacion
 * Acceso a miembros protegidos en la clase padre dentro de clase derivadas
 */

#include <iostream>
using namespace std;

// Declaracion de la clase Animal
class Animal {
    // Miembro privado: Solo se acceden dentro de la clase
    private:
        string color;
    
    // Miembro protegido: Se puede acceder en clases derivadas
    protected:
        string type;

    // Miembros publicos: Se puede acceder en otras funciones o clases
    public:
        // Imprime un mensaje de correr
        void run() { cout << "I can run -- BASE!" << endl; }

        // Imprime un mensaje de comer
        void eat() { cout << "I can eat!" << endl; }

        // Imprime un mensaje de dormir
        void sleep() { cout << "I can sleep!" << endl; }

        // Metodo para cambiar el valor de la variable color del objeto de Animal
        void setColor(string clr) { color = clr; }

        // Metodo que retorna el valor del atributo privado
        string getColor() { return color; }
};

// Declaracion de clase Dog (derivada de Animal)
class Dog : public Animal {
    public:
        // Imprime un mensaje de correr (Sobreescrito de la clase padre)
        void run() { cout << "I can run -- DERIVED!" << endl; }

        // Cambiar el valor de la variable type (protected -> Se puede acceder en el derivado)
        void setType(string tp) { type = tp; }

        // Metodo para mostrar la informacion del objeto Dog
        void displayInfo(string c) {
            // Recibe como parametro el color, en la clase padre esta privado (no se puede acceder)
            cout << "I am a " << type << endl;
            cout << "My color is " << c << endl;
        }
        /* void setColor(string clr) { color = clr; } */

        // Metodo nuevo de ladrar
        void bark() { cout << "I can bark! Woof woof!!" << endl; }
};

int main() {

    // Declaracion del objeto de clase Dog
    Dog dog1;

    // Ejecucion de metodos
    dog1.run(); // Version modificada en Dog
    dog1.eat();
    dog1.sleep();
    dog1.setColor("black"); // De la clase padre (si tiene acceso a color)

    dog1.bark(); // Nuevo metodo
    dog1.setType("Doberman"); 
    dog1.displayInfo(dog1.getColor());

    return 0;
}