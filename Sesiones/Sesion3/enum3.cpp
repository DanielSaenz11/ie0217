
#include <iostream>
using namespace std;

// Declaracion del enum
enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
} card; // Declaracion de variable card del tipo suit

int main() {
    card = club;

    // Imprimir el tamano de la variable
    cout << "Size of enum variable " << sizeof(card) << " bytes." << endl;
    
    return 0;
}

