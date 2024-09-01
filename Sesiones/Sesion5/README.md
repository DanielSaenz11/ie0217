# Sesión 5: Manejo de Memoria, Estructuras de Datos y Algoritmos

Esta sesión corresponde a la realizada para el 3 de setiembre del 2024, correspondiente al tema de manejo de memoria, análisis de algoritmos y estructuras de datos.

En el directorio actual, se encuentran los siguientes subtemas desarrollados:

### Almacenamiento de datos en la memoria en C++

Se describe el funcionamiento del _stack_, del _heap_ y de los _data segments_

- __tiposMemoria.cpp__: Este programa contiene la demostración del uso de los tipos de memoria en C++: variables globales, locales (stack) y dinámicas (heap).

### Memoria dinámica

Consiste en una introducción al manejo de memoria dinámica en C++. Se utiliza el comando `new` para reservarla y `del` para liberarla, respectivamente.

- __memoriaDinamica1.cpp__: Contiene una introducción al uso de memoria dinámica, _allocate_ memoria (reservar) y _de-allocate_ memoria (liberar).

- __memoriaDinamica2.cpp__: Explicación del uso de punteros con memoria dinámica.
- __memoriaDinamica3.cpp__: Implementación de memoria dinámica para arrays.
- __memoriaDinamica4.cpp__: Uso de memoria dinámica con clases y objetos.

- __malloc.cpp__: Explicación del uso de la función `malloc()` para reservar memoria dinámica.

- __calloc.cpp__: Uso de `calloc()` para inicializar memoria dinámica reservada en 0.

- __realloc.cpp__: Explicación de _re-allocating_ memoria en C++ (cambiar el tamaño de la memoria reservada).

### Estructuras de datos

Se analizan las implementaciones de estructuras de datos básicas, como el stack/pila, el queue/cola, la lista enlazada y el árbol. 

- __stack.cpp__: Contiene la implementación básica de un stack o pila.

- __queue.cpp__: Implementación de un queue o cola, por medio de una clase `Queue`.

- __linkedList.cpp__: Listas enlazadas por medio de una clase `Node`, que contienen el valor del nodo y un puntero al siguiente nodo.

- __arbol.cpp__: Recorrido en orden, _preorder_ y _postorder_ de un árbol. 

## Modo de uso

Para ejecutar los programas, es necesario que se tenga instalado el compilador `g++` para ejecutar el código de C++.

A modo general, la mayoría de programas contienen únicamente un archivo de fuente. Por ende, se sugiere el siguiente comando, dentro del directorio actual `./ie0217/Sesiones/Sesion5/`:

```
g++ -o nombrePrograma.exe nombrePrograma.cpp
```

Para ejecutarlos, se requiere el comando a continuación:

```
./nombrePrograma.exe
```

Para eliminar el ejecutable, se utiliza el comando en Linux (Unix-based):
```
rm nombrePrograma.exe
```

En Windows, se utiliza el comando:
```
del nombrePrograma.exe
```

__Nota__: Si se compilan los archivos en el sistema operativo Windows, es posible que al ejecutar o especificar direcciones de archivos, se requiera utilizar `\` en lugar de `/`.