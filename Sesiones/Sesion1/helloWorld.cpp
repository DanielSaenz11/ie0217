/*
Primer programa en C++

Explicacion de git:
1) Al crear este archivo y modificarlo, git indica que no se estan
   rastreando los cambios | git status
2) Se debe incluir en el staging area | git add [nombreArchivo]
3) Se realiza un commit de los cambios realizados con firma y un
   mensaje descriptivo | git commit -s -m "mensaje"
4) Se envian los cambios al servidor en remoto | git push
*/

// Biblioteca para manejar entrada y salida
#include <iostream>

int main() {
    // Imprimir en consola string en ingles
    std::cout << "Hello World!";
    return 0;
}