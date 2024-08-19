/**
 * Sobrecarga de funciones
 * 
 * Funciona cuando:
 * 1) las funciones tienen el mismo nombre
 * 2) tienen distinto numero de parametros
 */


#include <iostream>
using namespace std;

// Se coloco un return arbitrario para que no se presentara un warning
int test() {return 0;}
int test(int a) {return a;}
int test(double a) {return a;}
int test(int a, double b) {return a + (int) b;}

int main(int argc, char* argv[]) {

    return 0;
}