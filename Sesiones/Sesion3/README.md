# Sesion 3

Esta sesión corresponde al trabajo previo que se debió realizar para el martes 20 de agosto del 2024.

En el presente directorio, se tratan las bases del lenguaje de programación C++ que se muestran a continuación:

1) Source files y header files
2) Type casting
3) Sentencia `goto`
4) Recursividad
5) Enums
6) Directiva de preprocesador `#define`
7) Direcciones de memoria
8) Punteros
9) Punteros y structs
10) Punteros y arreglos
11) Punteros y funciones
12) Punteros dobles

## Modo de uso
Con respecto al modo de uso, todos los archivos que se encuentran en el directorio deben ser compilados con `g++`.

El comando sugerido para compilar en la terminal es:

```
g++ -o nombreArchivo.exe nombreArchivo.cpp
```

Para ejecutar el archivo ejecutable producto del proceso de compilación, se utiliza el comando:

```
./nombreArchivo.exe
```

Hay algunas excepciones que requieren un comando distinto para ser compilados.

En cuanto al ejercicio inicial de header files, este se compone de 3 archivos: `sum.cpp` (source file), `sum.hpp` (header file) y `headerFile1.cpp`/`headerFile2.cpp` (contiene la función main). Por lo tanto, se sugiere el siguiente comando:

```
g++ -o headerFile.exe sum.cpp headerFile1.cpp
```
El mismo comando se utiliza para `headerFile2.cpp`, sólo se cambia por `headerFile1.cpp`.
