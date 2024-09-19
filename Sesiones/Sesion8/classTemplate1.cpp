/*
Class templates
Permiten crear una única clase y poder trabajar con distintos tipos de datos

Boilterplate:
template <class T>
class className {
    private:
        T var;
        ...

    public:
        T functionName(T arg);
        ...
};

 */

#include <iostream>
using namespace std;

template <class T>
class Number {
    private:
        T num;

    public:
        // Definición del constructor: Recibe un tipo de dato T
        Number(T n) : num(n) {}

        // Función getter de atributo num
        T getNum() {
            return num; // Tipo de dato T
        }
};

int main() {
    // Crear un objeto de tipo entero
    Number<int> numberInt(7);

    // Crear un objeto de tipo double
    Number<double> numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}