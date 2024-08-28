/**
 * Codigo de la presentacion
 * Definir el comportamiento de operadores (+,-,*,/) para clase
 * 
 * class className {
 *     public:
 *         returnType operator symbol (arguments) {
 *             ...
 *         }
 * };
 */


#include <iostream>
using namespace std;

class Fraccion {

    // Declaracion de variables dentro de la clase
    int numerador, denominador;

    public:
        // Constructor de clase Fraccion
        Fraccion(int n, int d) : numerador(n), denominador(d) {}

        // Sobrecarga de operador (+)
        Fraccion operator+ (const Fraccion &f) {
            
            /* Creacion de objeto resultado donde contiene el numerador
             y denominador resultantes */
            Fraccion resultado(
                numerador * f.denominador + f.numerador * denominador,
                denominador * f.denominador
            );
            // Retornar el objeto creado
            return resultado;
        }

        // Metodo para imprimir la fraccion
        void imprimir() {
            cout << numerador << "/" << denominador << endl;
        }
};

int main() {
    // Declaracion de los objetos Fraccion
    Fraccion f1(1, 2);
    Fraccion f2(3, 4);

    // Uso de sobrecarga de operador +
    Fraccion f3 = f1 + f2;

    // Imprimir el resultado de suma de fracciones
    f3.imprimir();

    return 0;
}