/**
 * Acceso a los componentes de un struct con un puntero por medio de: (*ptr).component
 */

#include <iostream>
using namespace std;

// Declaracion del struct Distance
struct Distance {
    int feet;
    float inch;
};

int main() {
    // Declaracion de puntero y variable tipo struct Distance
    Distance *ptr, d;

    // Asignar la direccion de la variable al struct
    ptr = &d;

    // Input de los componentes del struct con punteros
    cout << "Enter feet: ";
    cin >> (*ptr).feet;

    cout << "Enter inch: ";
    cin >> (*ptr).inch;

    // Mostrar la informacion al acceder por medio de punteros
    cout << "Displaying information." << endl;
    cout << "Distance = " << (*ptr).feet << " feet " << (*ptr).inch << " inches";

    return 0;
}