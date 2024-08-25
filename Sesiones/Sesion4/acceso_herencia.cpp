/**
 * Codigo de la presentacion
 * Tipos de acceso al realizar herencia en C++
 */

#include <iostream>
using namespace std;

// Declaracion de clase padre
class Base {
    // Miembro publico
    public:
        int x;

    // Miembro protegido
    protected:
        int y;

    // Miembro privado
    private:
        int z;
};

class PublicDerived : public Base {
    // x es publico
    // y es protected
    // z es no es accesible en PublicDerived
};

class ProtectedDerived : protected Base {
    // x es protected
    // y es protected
    // z es no es accesible en ProtectedDerived
};

class PrivateDerived : private Base {
    // x es private
    // y es private
    // z es no es accesible en PrivateDerived
};
