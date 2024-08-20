# Sesion 2

Esta sesión corresponde al trabajo previo que se debió realizar para el martes 20 de agosto del 2024.

En el presente directorio, se tratan las bases del lenguaje de programación C++ que se muestran a continuación:
1) Compilador g++
2) Archivo helloWord.cpp
3) Tipos de datos en C++
4) Variables y su scope
5) Modificadores de tipo de dato
6) Literales
7) Entrada y salida del usuario `cin` y `cout`.
8) Operadores
9) Sentencia de toma de decisiones `if-else` y `switch-case`
10) `for` loop
11) `while` loop
12) `do-while` loop
13) Arreglos de datos
14) Funciones
15) Argumentos de funciones
16) Argumentos de `main`
17) Sentencia `return`
18) Prototipo de funciones
19) Sobrecarga de funciones
20) Valores predeterminados en parámetros de funciones
21) `static` y `extern` keywords
22) Structs

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

En cuanto a los archivos `extern1.cpp` y `extern2.cpp`, se deben de compilar ambos archivos juntos para que el compilador reconozca de dónde se obtiene la variable con el keyword `extern`. Por ende, el comando sugerido es el siguiente:

```
g++ -o extern.exe extern1.cpp extern2.cpp
```

