#ifndef PROGRAMA1_HPP
#define PROGRAMA1_HPP

// Declaracion de los enums de unidades
enum Longitud { Metro, Kilometro, Centimetro, Milla, Pulgada };
enum Peso { Gramo, Kilogramo, Libra, Onza };
enum Temperatura { Celsius, Fahrenheit, Kelvin };

// Structs con factores de conversion
struct ConversionLongitud {
    Longitud unidadOrigen;
    Longitud unidadDestino;

    // Unidad a metro
    double factorMetro = 1;
    double factorKilometro = 1000;
    double factorCentimetro = 0.01;
    double factorMilla = 1609.34;
    double factorPulgada = 0.0254;
};
struct ConversionPeso {
    Peso unidadOrigen;
    Peso unidadDestino;

    // Unidad a gramo
    double factorGramo = 1;
    double factorKilogramo = 1000.0;
    double factorLibra = 453.592;
    double factorOnza = 28.3495;
};
struct ConversionTemperatura {
    Temperatura unidadOrigen;
    Temperatura unidadDestino;
};

double convertir(ConversionLongitud conversion, double valor);
double convertir(ConversionPeso conversion, double valor);
double convertir(ConversionTemperatura conversion, double valor);


#endif // PROGRAMA1_HPP