
#include <iostream>
using namespace std;

// Declaracion de enum
enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
// Sunday = 0, ... Saturday = 6

int main() {
    week today;

    // Asignacion de valor especifico
    today = Wednesday;

    // +1 para ajustar el indice (enum comienza en 0)
    cout << "Day: " << today+1 << endl;

    return 0;
}

