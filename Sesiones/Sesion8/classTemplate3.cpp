/*
Class Templates con múltiples parámetros

// Template con tres tipos de datos y V tiene valor por defecto int
template <class T, class U, class V = int>
class ClassName {
    private:
        T member1;
        U member2;
        V member3;
    public:
        ...
};

*/

#include <iostream>
using namespace std;

// Declaración de template class
template <class T, class U, class V = char> // Se coloca V como char por defecto
class ClassTemplate {
    private:
        // Miembros de cada tipo de dato del template
        T var1;
        U var2;
        V var3;

    public:
        // Constructor de la clase
        ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}

        // Función miembro para imprimir el valor de cada atributo (independiente del tipo)
        void printVar() {
            cout << "var1 = " << var1 << endl;
            cout << "var2 = " << var2 << endl;
            cout << "var3 = " << var3 << endl;
        }
};

int main() {
    // Crear objeto con tipos int, double y char (por defecto)
    ClassTemplate<int, double> obj1(7, 7.7, 'c');

    // Imprimir valores de los miembros de obj1
    cout << "obj1 values: " << endl;
    obj1.printVar();

    // Crear objeto con tipos double, char y bool
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
    
    // Imprimir valores de los miembros de obj2
    cout << "\nobj2 values: " << endl;
    obj2.printVar();

    return 0;
}