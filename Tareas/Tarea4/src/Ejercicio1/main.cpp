/**
 * @file main.cpp
 * @brief Programa para realizar benchmarking de algoritmos de ordenamiento en C++.
 * 
 * @details Este programa compara los tiempos de ejecución de diferentes algoritmos de ordenamiento 
 * (Bubble Sort, Selection Sort, Insertion Sort, Quick Sort y sort) en vectores generados 
 * aleatoriamente. También permite la personalización del tamaño del conjunto de datos y la selección
 * de qué algoritmos ejecutar mediante el uso de argumentos o a través del Makefile1.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 04/10/2024
 */

#include "sorting.hpp" // Incluir header file con declaración de algoritmos de sorting
#include <chrono> // Para medir tiempo
#include <regex> // Validar tamaño ingresado por el usuario

using namespace std;

/**
 * @brief Mide el tiempo de ejecución de una función de ordenamiento.
 * 
 * Esta función toma un algoritmo de ordenamiento como argumento y mide el tiempo de ejecución
 * del mismo sobre un conjunto de datos.
 * 
 * @tparam T El tipo de los elementos del vector (generalmente int).
 * @tparam Func El tipo de la función de ordenamiento.
 * @param sortFunction La función de ordenamiento a medir.
 * @param data El vector de datos sobre el cual se aplicará el algoritmo de ordenamiento (copia interna).
 * @return El tiempo de ejecución en segundos del algoritmo de ordenamiento.
 */
template <typename T, typename Func>
double measureSortTime(Func sortFunction, vector<T> data) {
    // Tiempo de inicio del cronómetro
    auto start = chrono::high_resolution_clock::now();
    
    // Ejecutar algoritmo con data (se pasa por valor, haciendo una copia interna)
    sortFunction(data); 

    // Medición de tiempo de finalización
    auto end = chrono::high_resolution_clock::now();

    // Retorna el tiempo total de ejecución algoritmo (redondeado a 4 decimales)
    return round(chrono::duration_cast<chrono::microseconds>(end - start).count() / 100.0 ) / 10000.0;
}

/**
 * @brief Verifica si un tamaño de conjunto de datos es válido.
 * 
 * Esta función usa una expresión regular para validar si una cadena ingresada representa
 * un número válido para el tamaño del conjunto de datos.
 * 
 * @param input La cadena de entrada que representa el tamaño del conjunto de datos.
 * @return `true` Si la cadena es un tamaño válido.
 * @return `false` Si la cadena no es un tamaño válido.
 */
bool isValidSize(const string& input) {
    regex pattern("^[1-9][0-9]*$"); // Valores numéricos
    return regex_match(input, pattern);
}

/**
 * @brief Función principal que ejecuta el benchmarking de algoritmos de ordenamiento.
 * 
 * Esta función genera conjuntos de datos aleatorios y mide el tiempo de ejecución de diferentes
 * algoritmos de ordenamiento, que pueden ser seleccionados por el usuario. También permite
 * especificar un tamaño personalizado de conjunto de datos a través de la línea de comandos.
 * 
 * @param argc El número de argumentos proporcionados por línea de comandos.
 * @param argv Los argumentos proporcionados por línea de comandos.
 * @return int Código de retorno de la función (0 en caso de éxito).
 */
int main(int argc, char* argv[]) {

    // Tamaño de vectores predeterminados
    vector<size_t> sizes = {5000, 10000, 50000, 100000, 200000, 500000};

    // Variable booleana por si se ingresa un tamaño predeterminado
    bool isCustomSize = false;
    size_t customSizeValue = 0;

    // Algoritmos para ejecutar
    string algosEjecucion = "all";

    // Número de ejecuciones
    int numRuns = 10;

    // Si se ingresaron argumentos por la línea de comandos
    if (argc > 1) {
        // Recorrer la lista de argumentos
        for (int i = 1; i < argc; i++) {

            string arg = argv[i]; // Elemento actual del argv

            // Si el arg es --size y contiene un elemento después de este -> size
            if (arg == "--size" && i + 1 < argc) {
                // Si el tamaño es un argumento válido: Evaluar con regex
                if (isValidSize(argv[i + 1])) {
                    isCustomSize = true;
                    customSizeValue = stoul(argv[i + 1]);
                } else {
                    // Si el tamaño no es válido
                    cerr << "Tamaño inválido: " << argv[i + 1] << endl;
                    return 1; // Retornar código de estado de error
                }
            }

            // Si el arg es --algorithms y tiene un elemento después de él -> algos
            if (arg == "--algorithms" && i + 1 < argc) {
                algosEjecucion = argv[i + 1];
            }

            // Si el arg es --runs
            if (arg == "--runs" && i + 1 < argc) {
                if (isValidSize(argv[i + 1])) {
                    numRuns = std::stoi(argv[i + 1]);
                } else {
                    cerr << "Número de ejecuciones inválido: " << argv[i + 1] << endl;
                    return 1;
                }
            }
        }
    }

    // Si se ingresó un tamaño personalizado, se cambia el tamaño
    if (isCustomSize) {
        sizes = {customSizeValue};
    }


    for (int runIndex = 0; runIndex < numRuns; runIndex++) {
        cout << "--- Número de ejecución: " << runIndex + 1 << " ---" << endl;


        // Recorrer cada uno de los tamaños y ejecutar los algoritmos indicados
        for (auto size : sizes) {
            cout << "Tamaño del conjunto de datos: " << size << endl;

            // Generar vector del tamaño ingresado
            vector<int> data = generateRandomVector<int>(size);

            // Validación de condiciones para ejecutar BubbleSort
            if (algosEjecucion == "all" || algosEjecucion.find("bubble") != string::npos) {
                // Ejecutar algoritmo para medir el tiempo
                double tiempoBubbleSort = measureSortTime(bubbleSort<int>, data);
                
                // Imprimir resultado
                cout << "Bubble Sort: " << tiempoBubbleSort << " segundos" << endl;
            }

            // Validación de condiciones para ejecutar SelectionSort
            if (algosEjecucion == "all" || algosEjecucion.find("selection") != string::npos) {
                // Ejecutar algoritmo para medir el tiempo
                double tiempoSelectionSort = measureSortTime(selectionSort<int>, data);

                // Imprimir resultado
                cout << "Selection Sort: " << tiempoSelectionSort << " segundos" << endl;
            }

            // Validación de condiciones para ejecutar InsertionSort
            if (algosEjecucion == "all" || algosEjecucion.find("insertion") != string::npos) {
                // Ejecutar algoritmo para medir el tiempo
                double tiempoInsertionSort = measureSortTime(insertionSort<int>, data);

                // Imprimir resultado
                cout << "Insertion Sort: " << tiempoInsertionSort << " segundos" << endl;
            }

            // Validación de condiciones para ejecutar QuickSort
            if (algosEjecucion == "all" || algosEjecucion.find("quick") != string::npos) {
                // Ejecutar algoritmo para medir el tiempo
                double tiempoQuickSort = measureSortTime(quickSortWrapper<int>, data);

                // Imprimir resultado
                cout << "Quick Sort: " << tiempoQuickSort << " segundos" << endl;
            }

            // Validación de condiciones para ejecutar STL sort
            if (algosEjecucion == "all" || algosEjecucion.find("stl") != string::npos) {
                // Ejecutar algoritmo para medir el tiempo: Se utiliza una función lambda
                double tiempoSTLSort = measureSortTime([](vector<int>& arr) { sort(arr.begin(), arr.end()); }, data);

                // Imprimir resultado
                cout << "STL Sort: " << tiempoSTLSort << " segundos" << endl;
            }

            cout << "---------------------------------------------" << endl;
        }
    }

    return 0;
}
