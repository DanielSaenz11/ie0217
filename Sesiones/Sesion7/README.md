# Sesión 7: Standard Template Library (STL)

Esta sesión corresponde a la realizada para el 13 de setiembre del 2024, correspondiente al uso de la Standard Template Library.

En el directorio actual, se encuentran los siguientes subtemas desarrollados:

### <ins>Containers</ins>

Se implementaron ejemplos de uso de distintos tipos de _containers_ en los archivos a continuación:

- __vector.cpp__: Se describe la forma de declarar este contener secuencial y se recorre cada uno de sus elementos con un `for` loop.

- __set.cpp__: Se inicializa un container de tipo `set` (sin repetición) y se imprimen sus elementos.

- __unordered_set.cpp__: Se inicializa un container de tipo `unordered_set` y se imprime su contenido por medio de un loop.

- __map.cpp__: Se declara un container de tipo `map` y se utiliza el método `insert()` y `[]` para agregar elementos.

- __containerAdapters.cpp__: Se utiliza el adaptador de contenedor `stack`, se hace `push()` a los elementos y luego se recorre, por medio de `top()` y `pop()`.

### <ins>Iteradores</ins>

Se analizan los diferentes tipos de iteradores, junto con ejemplos de su uso.

- __iterators1.cpp__: Declaración básica de iteradores en C++ de `vector` y `map`.

- __iterators2.cpp__: Implementación de iteradores para recorrer un container `vector`.

- __iteradoresEntradaSalida.cpp__: Declaración de iteradores de entrada y salida (consola).

- __forwardList.cpp__: Inicialización e iteración con un iterador en un `forward_list`, donde se muestra el funcionamiento de `*` (desrefencia del iterador) y `++` para moverse hacia adelante.

- __iteradoresBidireccionales.cpp__: Movimiento hacia adelante y atrás por medio un iterador bidireccional en un `list`.

- __iteradoresAccesoAleatorio.cpp__: Uso de `[]` y `*` para acceder a posiciones específicas de containers.

- __STL_algoritmos.cpp__: Uso de sorting para un vector por medio de los algoritmos implementados en la STL.

## Modo de uso

Para ejecutar los programas, es necesario que se tenga instalado el compilador `g++` para ejecutar el código de C++.

A modo general, los programas contienen únicamente un archivo de fuente. Por ende, se sugiere el siguiente comando, dentro del directorio actual `./ie0217/Sesiones/Sesion7/`:

```
g++ -o nombrePrograma.exe -std=c++11 nombrePrograma.cpp
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

Además, se presentan algunos casos especiales de archivos que utilizan propiedades que no se presentan en la versión predeterminada de C++ utilizada por el compilador, como _containers_ y _for_ loops con `auto`. Por lo tanto, se recomienda compilar con el flag `-std=c++11`, con el fin de evitar este problema.
