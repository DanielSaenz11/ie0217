#include "sorting.hpp" // Incluir header file con declaración de algoritmos de sorting

using namespace std;

// Función para medir tiempo de ejecución de un algoritmo de ordenamiento
template <typename Func> // Uso de template Func para pasar función como parámetro
long long measure_sort_time(Func sort_function, vector<int>& data) {
    
    // Tiempo de inicio del cronómetro
    auto start = chrono::high_resolution_clock::now();
    
    // Ejecutar algoritmo con data como argumento
    sort_function(data); 

    // Medición de tiempo de finalización
    auto end = chrono::high_resolution_clock::now();

    // Retorna el tiempo total de ejecución algoritmo
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Función main(): Punto de entrada de ejecución del programa
int main() {
    // Tamaños de prueba
    vector<size_t> sizes = {5000, 10000, 20000, 30000, 40000, 50000};

    // Comparación de tiempos de varios algoritmos de ordenamiento
    for (auto size : sizes) {

        // Vector data que se va a utilizar para obtener el tiempo de ejecución del algoritmo
        vector<int> data = generate_random_vector(size);

        // Medir tiempo de Bubble Sort
        vector<int> bubble_data = data;
        long long bubble_time = measure_sort_time(bubble_sort, bubble_data); // Retorna el tiempo total que duró
        cout << "Bubble Sort - Tamaño: " << size << " - Tiempo: " << bubble_time << " ms\n"; // Impresión del resultado

        // Medir tiempo de Selection Sort
        vector<int> selection_data = data;
        long long selection_time = measure_sort_time(selection_sort, selection_data); // Retorna el tiempo total que duró
        cout << "Selection Sort - Tamaño: " << size << " - Tiempo: " << selection_time << " ms\n"; // Impresión del resultado

        // Medir tiempo de Insertion Sort
        vector<int> insertion_data = data;
        long long insertion_time = measure_sort_time(insertion_sort, insertion_data); // Retorna el tiempo total que duró
        cout << "Insertion Sort - Tamaño: " << size << " - Tiempo: " << insertion_time << " ms\n"; // Impresión del resultado

        // Medir tiempo de STL Sort (algoritmo implementado en la Standard Template Library)
        vector<int> stl_data = data;

        // Se ejecuta std::sort() con todo el vector de datos
        long long stl_time = measure_sort_time([](vector<int>& arr) { sort(arr.begin(), arr.end()); }, stl_data);
        cout << "STL Sort - Tamaño: " << size << " - Tiempo: " << stl_time << " ms\n"; // Impresión del resultado

        cout << "---------------------------------------------\n";
    }

    return 0;
}
