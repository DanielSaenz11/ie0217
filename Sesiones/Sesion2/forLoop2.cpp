/**
 * for Loop en su forma iteradora sobre un arreglo de datos
 * Recorre cada una de las entradas
 * 
 * Da un warning por utilizar range-based for loop pues esto es de C++ 11
 * Para compilar se utiliza: g++ -std=c++11 -o forLoop2.exe forLoop2.cpp
 */

#include <iostream>
using namespace std;

int main() {
    
    int num_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    for (int n: num_array) {
        // 1 2 3 4 5 6 7 8 9 10
        cout << n << " ";
    }

    return 0;
}