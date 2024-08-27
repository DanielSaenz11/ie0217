#include <iostream>
#include "programa1.hpp"

using namespace std;

double convertir(ConversionLongitud conversion, double valor) {
    // enum Longitud { Metro, Kilometro, Centimetro, Milla, Pulgada };

    switch (conversion.unidadOrigen) {
        case Metro:
            valor *= conversion.factorMetro;
            break;
        case Kilometro:
            valor *= conversion.factorKilometro;
            break;
        case Centimetro:
            valor *= conversion.factorCentimetro;
            break;
        case Milla:
            valor *= conversion.factorMilla;
            break;
        case Pulgada:
            valor *= conversion.factorPulgada;
            break;
        default:
            cout << "Error: Unidad de origen no existe" << endl;
            return -1;
    }

    switch (conversion.unidadDestino) {
        case Metro:
            valor /= conversion.factorMetro;
            break;
        case Kilometro:
            valor /= conversion.factorKilometro;
            break;
        case Centimetro:
            valor /= conversion.factorCentimetro;
            break;
        case Milla:
            valor /= conversion.factorMilla;
            break;
        case Pulgada:
            valor /= conversion.factorPulgada;
            break;
        default:
            cout << "Error: Unidad de destino no existe" << endl;
            return -1;
    }

    return valor;
}

double convertir(ConversionPeso conversion, double valor) {
    // enum Peso { Gramo, Kilogramo, Libra, Onza };

    switch (conversion.unidadOrigen) {
        case Gramo:
            valor *= conversion.factorGramo;
            break;
        case Kilogramo:
            valor *= conversion.factorKilogramo;
            break;
        case Libra:
            valor *= conversion.factorLibra;
            break;
        case Onza:
            valor *= conversion.factorOnza;
            break;
        default:
            cout << "Error: Unidad de origen no existe" << endl;
            return -1;
    }

    switch (conversion.unidadDestino) {
        case Gramo:
            valor /= conversion.factorGramo;
            break;
        case Kilogramo:
            valor /= conversion.factorKilogramo;
            break;
        case Libra:
            valor /= conversion.factorLibra;
            break;
        case Onza:
            valor /= conversion.factorOnza;
            break;
        default:
            cout << "Error: Unidad de destino no existe" << endl;
            return -1;
    }

    return valor;
}

double convertir(ConversionTemperatura conversion, double valor) {
    // enum Temperatura { Celsius, Fahrenheit, Kelvin };

    // Unidades a Celsius
    switch (conversion.unidadOrigen) {
        case Celsius:
            break;
        
        case Fahrenheit:
            valor = 5/9 * (valor - 32);
            break;

        case Kelvin:
            valor -= 273.15;
            break;

        default:
            cout << "Error: Unidad de destino no existe" << endl;
            return -1;
    }

    switch (conversion.unidadDestino) {
        case Celsius:
            break;
        case Fahrenheit:
            valor = 9/5 * valor + 32;
            break;
        case Kelvin:
            valor += 273.15;
            break;
        default:
            cout << "Error: Unidad de destino no existe" << endl;
            return -1;
    }

}

