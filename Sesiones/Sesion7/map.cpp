/**
 * Mapa: Contener asociativo
 * 
 * Pares llave-valor -> Se accede a los valores por medio de las llaves
 * 
 * std::map<key_type, value_type> map_name = {{key1, value1}, {key2, value2}, ...};
 */

#include <iostream>
#include <map> // map container

using namespace std;

// Funcion main(): Punto de entrada de ejecución del programa
int main() {
    // Declaracion de map con llave entera y valor string
    map<int, string> student;

    // Uso de [] para agregar pares llave-valor al map
    student[1] = "Jacqueline";
    student[2] = "Blake";

    // Uso de insert() para agregar pares al map
    // make_pair() convierte en pares a los argumentos
    student.insert(make_pair(3, "Denise"));
    student.insert(make_pair(4, "Blake")); // Valor duplicado: No afecta

    // Elementos con llaves duplicadas
    student[5] = "Timothy";
    student[5] = "Aaron"; // Se sustituye el anterior por este

    // Imprimir elementos del map
    for (int i = 1; i <= student.size(); ++i) {
        cout << "Student[" << i << "]: " << student[i] << endl;
    }

    return 0;
}