# Sesión 4: Clases y Objetos

Esta sesión corresponde a la realizada para el 27 de agosto del 2024. C++ es un lenguaje de programación orientado a objetos. Por lo tanto, en esta sesión se trata este tema.

En el directorio actual, se encuentran los siguientes subtemas desarrollados:

### Boilerplate de una clase.

- `class.cpp`: Principios de declaración de clases y su uso.
- `boilerplate_clase1.cpp`: Propiedades básicas de una clase.
- `boilerplate_clase2.cpp`: Cambio en el valor de atributos de una clase.
- `boilerplate_clase3.cpp` y `boilerplate_clase4.cpp`: Variantes del constructor.
- `metodos_clase1.cpp` y `metodos_clase2.cpp`: Uso de métodos públicos en clases.

### Destructor de objetos de clase.

- `destructor1.cpp`: Demostración para una clase de Archivo.
- `destructor2.cpp`: Ejemplo para la clase _Molde_.

### Tipos de acceso en clases: _public_, _protected_, _private_.

- `tipos_acceso.cpp`: Demostración de elementos _public_, _protected_, _private_.

### Objetos como parámetros y retorno de funciones.

- `objetoParametro.cpp`: Paso de objetos de clases como parámetro de funciones.
- `objetoRetorno.cpp`: Retorno de objetos de clases en funciones.

### Archivos de encabezado, de código fuente y función `main()` separados

- Directorio `./ejemplo_persona`: Consiste de un programa con el archivo fuente de `persona.cpp` (donde se programa la clase), archivo de encabezado `persona.hpp` (donde se declara la clase) y `main.cpp` (donde se encuentra la función _main_).
- Directorio `./ejemplo_student`: Programa donde se maneja la funcionalidad de las calificaciones de estudiantes. Está conformado por los archivos de `funciones.cpp` y `student.cpp` (código fuente), `funciones.hpp` y `student.hpp` (header files) y el archivo `main.cpp` (punto de entrada de ejecución del programa pues contiene a _main()_).

### Sobrecarga de operadores.

- `sobrecarga_operadores.cpp`: Asignación de operadores especiales en clases.

### Herencia multinivel, múltiple y jerárquica.

- `herencia.cpp`: Principios básicos de herencia de propiedades de una clase a otra derivada.
- `herencia_multinivel.cpp`: Demostración de herencia en varios niveles de clases.
- `herencia_multiple.cpp`: Herencia en una clase que toma como _padres_ a dos o más clases.
- `herencia_jerarquica.cpp`: Varias clases _hijo_ con una misma clase _padre_.

### Sobreescritura de funciones en herencia.

- `sobreescrituraHerencia1.cpp` y `sobreescrituraHerencia2`: Sobreescritura de elementos en la clase derivada respecto a la clase hijo.

### Modos de acceso al realizar herencia.

- `miembros_protegidos.cpp`: Uso de diferentes modos de acceso en herencia.
- `acceso_herencia.cpp`: Tipo de acceso _public_, _protected_, _private_ al realizar herencia de elementos de una clase a otra.

### Funciones y clases amigas (keyword _friend_).

- `funcion_amiga1.cpp` y `funcion_amiga2.cpp`: Demostración de funciones amigas (_friend functions_).
- `clase_amiga.cpp`: Clases amigas en la dentro de una clase.

### Funciones virtuales (keyword _virtual_).

- `funciones_virtuales1.cpp`, `funciones_virtuales2.cpp` y `funciones_virtuales3.cpp`: Puntero de la clase padre apunta a objeto de la clase derivada.

## Modo de uso

A modo general, la mayoría de programas contienen únicamente un archivo de fuente. Por ende, se sugiere el siguiente comando, dentro del directorio actual:

```
g++ -o nombrePrograma.exe nombrePrograma.cpp
```

Ahora bien, para los proyectos dentro de los directorios `./ejemplo_persona` y `./ejemplo_student`, como se poseen archivos de encabezado, archivos de código fuente y un archivo designado con la función `main()`, se tienen comandos especiales.

En cuanto a `./ejemplo_persona` se tiene que el comando sugerido corresponde a:

```
g++ -o ejemplo_persona.exe ./ejemplo_persona/main.cpp ./ejemplo_persona/persona.cpp
```

Con respecto a `./ejemplo_student`, el comando sugerido corresponde:

```
g++ -o ejemplo_student.exe ./ejemplo_student/main.cpp ./ejemplo_student/funciones.cpp ./ejemplo_student/student.cpp
```

Para ejecutar los archivos ejecutables con terminación `.exe`, se utiliza el siguiente comando:

```
./nombreArchivo.exe
```

__Nota__: Si se compilan los archivos en el sistema operativo Windows, es posible que al ejecutar o especificar direcciones de archivos, se requiera utilizar `\` en lugar de `/`.

