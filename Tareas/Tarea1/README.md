# Tarea 1

Esta corresponde a la _Tarea 1_ del curso IE-0217, en la cual se tratan los principios del lenguaje de programación C++. La asignación está dividida en tres partes:

1) Preguntas teóricas sobre C++.
2) Ejercicio de __Conversión de unidades__.
3) Ejercicio de __Calculadora de Estadísticas y Búsqueda en un Arreglo__.

Las secciones mencionadas se desarrollan a continuación.

## Preguntas teóricas

En esta sección se van a responder a las preguntas propuestas por el profesor sobre los principios de C++.

### 1. ¿Cuáles son las diferencias entre los lenguajes compilados e interpretados? Brinde un ejemplo de cada uno.

Se presentan diferencias marcadas entre los lenguajes del tipo compilado e interpretado.

Primeramente, en cuanto al proceso de ejecución del código, se tiene que en los lenguajes compilados, el código se traduce a un lenguaje de bajo nivel por un compilador (_g++_ en el caso de C++); el código de máquina generado por el compilador fue hecho específicamente para la arquitectura de la computadora en cuestión. Por esta razón, cuando se distribuye código de lenguajes compilados, se envía el código fuente, no el ejecutable. Ahora bien, respecto a los lenguajes interpretados, estos se ejecutan línea por línea por medio de un intérprete; es decir, no se genera un archivo ejecutable.

El siguiente punto está relacionado con el anterior, pues los lenguajes compilados, por lo general, son más rápidos, debido a la compilación previa del código.

Durante el proceso de compilación, también se pueden detectar errores del tipo sintácticos, mientras que en los interpretados, es necesario ejecutar el programa para detectarlos.

Un ejemplo de un lenguaje de programación compilado corresponde a __C++__ o __Rust__. Mientras que, uno interpretado sería __Python__.

### 2. ¿Qué son los tipos de datos en C++? ¿Cuáles son sus clasificaciones? Brinde dos ejemplos de cada clasificación.

Los tipos de datos en C++ son los indicadores de qué tipo de dato se guarda en cierta variable, las operaciones que se pueden realizar con la variable, así como la cantidad de memoria que vaya a ocupar esta. 

Se dividen en tipos de datos primarios, derivados y _user defined_ (definidos por el usuario). Los primarios son los básicos del lenguaje, como enteros __int__ y caracteres __char__.

Los derivados como su nombre lo indica derivan de los primitivos, como colecciones de datos primitivos __arrays__ y __punteros__ que guardan la direccion de datos primarios.

Finalmente, los definidos por el usuario son los tipos que permiten agrupar datos primitivos y derivados para realizar nuevos tipos y adaptar a las necesidades del programa en cuestión, por ejemplo. Entre los tipos definidos por el usuario, se encuentran las __clases__ y los _structs_.





### 3. Explique qué es un linker en el contexto de un lenguaje de programación compilado. ¿Cuál es su función principal y por qué es esencial en el proceso de compilación?

### 4. ¿Cuál es la diferencia entre usar el operador `=` y `==`? Brinde un ejemplo para cada uno.

El operador `=` consiste en el __operador de asignación__. Este se utiliza cuando se va a asignar un valor a una variable, por ejemplo. Su funcionamiento se ilustra en la porción de código a continuación:

```
int num = 1;
```

Se está asignando el valor de 1 a la variable _num_.

Ahora bien, el operador `==` corresponde al __operador de igualdad__. Se utiliza para comparar la igualdad entre dos valores. Al operar con él, se devuelve `true` si ambos valores son iguales o `false` si son distintos.

El ejemplo consiste en que se define `x` con el valor de 1. Luego, se coloca el operador de igualdad dentro de la condición del `if` para comprobar si el valor guardado en la variable `x` es igual a 1. En caso de serlo, se imprime un mensaje para indicar que se ejecuta el statement. 

```
int x = 1;

if (x == 1) {
    cout << "Se ejecuta" << endl;
}
```

### 5. Observe el siguiente código, indique qué imprime el programa en la iteración número 7 y 9 del ciclo, explique el porqué.

```
#include <iostream>
int main() {
    int sum = 0;
    int result = 0;

    for (int i=0; i <= 10; i++) {
        sum += i;

        result = (i % 3 == 0) ? sum : 0;
        std::cout << result << std::endl;
    }
    return 0;
}
```

### 6. Explique el proceso de pasar argumentos a la función principal. ¿Cuál es el primer elemento de `argv[ ]`?

El proceso para pasar argumentos a la función `main()` consiste en indicar en la función los parámetros a recibir, la sintaxis es la siguiente:

```
int main(int argc, char *argv[])
```

Se tiene que `int argc` corresponde a la cantidad de argumentos que se recibe en la línea de comandos (incluye el nombre del programa). Además, `char *argv[]` corresponde a un arreglo de punteros del tipo caracter, donde cada índice apunta a una cadena que representa el número del argumento indicado. 

Para responder a la segunda pregunta, `argv[0]` corresponde al nombre del programa; es decir, el primer elemento del arreglo es el nombre o parte de la ruta del ejecutable.

### 7. ¿Cuál es la diferencia entre declarar e inicializar una variable?

La acción de __declarar__ una variable consiste en indicar el nombre y tipo de la variable, corresponde a una forma de indicarle al compilador que existe la variable, pero no se le asigna un valor. También, se reserva su espacio en memoria. 

En cuanto a __inicializar__ una variable,esta consiste en asignarle un valor a la variable después de la declaración.

### 8. ¿Para qué sirven los modificadores en C++?

Los modificadores corresponden a palabras que se colocan como prefijos para cambiar propiedades de variables o funciones, así como el comportamiento de estas. Por ejemplo, están los modificadores `signed` y `unsigned` que modifican el rango de la variable numérica (admite números negativos en su rango o no, respectivamente). Además, los modificadores `short` y `long` también son utilizados para cambiar el tamaño de las variables en memoria y por ende, su rango varía proporcionalmente. Los anteriores son de gran utilidad en sistemas donde el uso eficiente de recursos es una prioridad.

Obtenido de: [C++ Type Modifiers - GeeksForGeeks](https://www.geeksforgeeks.org/cpp-type-modifiers/).

### 9. ¿Qué es la sobrecarga de funciones en C++ y cómo se utiliza?

La sobrecarga de funciones es una característica de C++ que permite definir funciones con el mismo nombre y tipo de retorno, pero con distinto número y tipo de parámetros. Esto es realmente útil para la simplificación del código y aumentar su legibilidad y comprensión. El compilador se encarga de entender cuál definición de la función utilizar basándose en las características mencionadas anteriormente.  

### 10. ¿Cuál es la diferencia entre una variable local y una local estática?

Primero, se tiene que la variable local se declara dentro de una función o bloque de código, tal que su _scope_ está limitado a ese bloque (no se puede acceder fuera de él). Respecto a su ciclo de vida, al terminar la ejecución de la función/bloque de código, la variable muere (se libera su memoria).

En segundo lugar, las variables locales estáticas comparten el mismo _scope_ de las locales regulares. Sin embargo, su tiempo de vida difiere, pues conserva su valor en las siguientes llamadas de la función, por ejemplo. Se inicializa y vive hasta que termine la ejecución del programa.

### 11. ¿Qué es el type casting? ¿Cuáles existen? Brinde un ejemplo de cada uno.

El _type casting_ consiste en el proceso de convertir una variable de un data type a otro en programación. En el caso de C++ existen 4 tipos principales:

1) `static_cast`

Este corresponde al más usado en C++ y se utiliza para realizar castings seguros de tipos de datos relacionados. La sintaxis es la siguiente:

```
static_cast<new_type> (expression);
```

2) `dynamic_cast`

Se utiliza para hacer casting downcasting; es decir, convertir de un puntero de una clase base a una clase derivada.

```
dynamic_cast<new_type> (expression);
```

3) `const_cast`

Este casting es empleado para modificar el prefijo de __const__ o __volatile__ de una variable. Normalmente, se utiliza temporalmente para modificar los valores de las variables. Sin embargo, se debe usar con cuidado porque pueden provocar indefiniciones.

```
const_cast<new_type> (expression);
```

4) `reinterpret_cast`

Este tipo de casting se utiliza para cambiar el tipo de un puntero a otro.

```
reinterpret_cast<new_type> (expression);
```

Como tipo adicional, se encuentra el casting implícito que ocurre cuando no va a haber pérdida de información al hacerlo.

```
int a = 1;
double b = a;
```

También está el casting clásico de C, que se utilizan los paréntesis __()__ antes de la variable para hacer el casting. 

```
int a = 1;
double b = (double)a;
```

Obtenido de: [Casting Operators in C++](https://www.geeksforgeeks.org/casting-operators-in-cpp/).

### 12. ¿Cuál es la principal diferencia entre un bucle _do-while_ y un bucle _while_?

El bucle _do-while_ realiza una ejecución del código dentro de llaves y luego se ejecuta cada repetición mientras se cumpla la condición en el _while_.

En cuanto al bucle _while_, desde el inicio, este se ejecuta únicamente si la condición se cumple; es decir, si la condición antes de entrar al loop no se cumple, no se ejecuta ninguna repetición del _while_.

### 13. Explique por qué es útil y común dividir el código en archivos `.hpp`, `.cpp` y `main.cpp` en C++. Describa el propósito específico de cada tipo de archivo.

La utilidad de dividir el código en archivos `.hpp`, `.cpp` y `main.cpp` radica en la modularidad del código. Al diseñar el proyecto de esta forma, se facilita la organización, el mantenimiento y la colaboración. Además, se separa la implementación del código en el archivo `.cpp`, mientras que se proporciona una interfaz del código en el `.hpp`.

Entonces, el propósito del archivo `main.cpp` consiste en que este es el punto de entrada y guía de ejecución del código (contiene las instrucciones principales). Se incluyen los archivos de encabezado creados.

Los archivos de encabezado `.hpp` contienen la __declaración__ de las funciones, variables globales, clases y estructuras de datos, entre otros, que se utilizan en los archivos del programa. Por esta razón, este corresponde a la interfaz del proyecto. Para utilizarlos, se necesita incluirlos por medio de `#include`.

Los archivos `.cpp` contienen la definición e implementación de las funciones, clases y demás código fuente, para ser accesados por medio del _header file_ en los archivos donde es incluido. También se conocen como _source files_ por esta razón.


### 14. ¿Qué hace la sentencia `goto` y por qué es considerada una mala práctica en la programación moderna? ¿Qué alternativas se pueden usar en su lugar?

La sentencia `goto` funciona de manera que permite saltarse código y dirigirse a una etiqueta definida. Es decir, cambia el flujo de ejecución del código y dependiendo de la complejidad del programa, resulta confusa de seguir el código y difícil de mantener. Además, existen casos donde puede que no se declaren o liberen datos correctamente por estos saltos entre código.

Entre las alternativas a esta secuencia, se encuentran los loops conocidos `for` y `while`, así como el uso de estructuras condicionales como `if-else`. Para manejar la interrupción de código, se recomienda utilizar los keywords `break` (para salir del loop), `continue` (para saltar una iteración del loop) y `return` (para salir de funciones). De esta forma, no se presentan saltos directos en el código, se sigue el flujo regular de ejecución.

### 15. ¿Para qué se utiliza la directiva `#ifndef` y por qué es importante?

`#ifndef` significa _si no se ha definido_ y consiste en una directiva de preprocesador que se utiliza en los _header files_ o archivos de cabecera para evitar la inclusión del archivo varias veces.

Su importancia radica en que así, se evita un uso de memoria innecesario, así como la redefinición de elementos que pueden generar errores y conflictos.

Funciona de tal forma que, si se no ha definido lo que se encuentra dentro de `#ifndef` y `#endif`, se define. En posteriores inclusiones, si ya se definió, esta parte es omitida.

### 16. ¿Qué es un puntero y para qué es útil? ¿Cómo se declara e inicializa?

Un puntero en C++ es una variable que almacena la dirección de memoria de otra variable. Las variables regulares contienen valores, pero los punteros contienen direcciones.

La forma de declararlos se muestra a continuación:

```
int num1 = 1;
int* ptr = &num1; // data_type* ptr_name = &var
int num2 = *ptr;
```

En el ejemplo anterior, se evidencia el uso de `*` después del _data type_ para indicar que se trata de un puntero, luego se escribe el nombre del variable puntero, esta es la declaración del puntero. En cuanto a la asignación de un valor (inicialización), se utiliza el operador `&` para acceder a la memoria de la variable `num`. Entonces, se guarda en el puntero la dirección de memoria de num.

También, se utiliza nuevamente el `*` para acceder a la memoria a la que apunta el puntero. Por eso, en el ejemplo, se le asigna a `num2` el contenido de la dirección a la apunta `ptr`, que sería el valor de `num1`.

La utilidad de los punteros consiste en que se puede acceder directamente al valor en memoria de la variable. Por lo tanto, es usado ampliamente en funciones donde se requiere modificar el valor de la variable fuera del _scope_ de la función. Otra aplicación de los punteros corresponde a la manipulación de memoria dinámica y estructuras dinámicas de datos. 


### 17. ¿Cuál es la diferencia entre pasar parámetros por valor, por referencia y por puntero?

Al pasar parámetros por valor, se crea una copia del valor fuera de la función, por ejemplo. Por lo tanto, se utiliza memoria adicional para la copia, la cual es la utilizada dentro de la función (se modifica la copia, no el valor fuera de la función).

```
// Los cambios no se realizan fuera de la funcion
void duplicar(int n) {
    n *= 2;
}
```

En cuanto al paso de parámetros por referencia, la función recibe la dirección de la variable argumento. Por lo tanto, al modificar la variable, los cambios se reflejan también en la variable original. 

```
// Se modifica n fuera de la funcion pues se recibe su direccion
void duplicar(int &n) {
    n *= 2;
}
```

Finalmente, en el paso de parámetros por puntero, se utilizan punteros para modificar variables o estructuras de datos que se encuentran fuera de la función. Los cambios también se reflejan en estos pues se recibió un puntero hacia ellos, no una copia de su valor.

```
// Modifica el valor al que apunta n
void duplicar(int* n) {
    *n *= 2;
}
```

### 18. Cuando se usa un puntero para apuntar a un arreglo en C++, ¿a qué valor o dirección apunta inicialmente? Describa cómo sería la forma de acceder a todos los datos de ese arreglo mediante el puntero.

Al utilizar punteros en un arreglo, no se apunta a todo el arreglo. Por la naturaleza de esta estructura, cada elemento de los índices se encuentra en memoria contigua. Por lo tanto, al apuntar con un puntero a un arreglo se apunta al primer índice de este.

La forma de declarar un puntero a un arreglo es la siguiente:

```
int arr[10];

// Forma 1
int* ptr = arr;

// Forma 2
int* ptr = arr[0];
```

Posteriormente, para acceder a las demás entradas del arreglo por medio del puntero, se debe de sumar el índice de interés al puntero, para moverse esa cantidad de espacios en memoria.

```
int arr[10];
int* ptr = arr;

// Indice 5
*(ptr + 5);
```

Por ejemplo, en el bloque de código anterior, se declaró un arreglo con 10 entradas. El puntero se asignó de la forma mencionada anteriormente. Ahora bien, para acceder a la entrada 5 del arreglo, se aumenta la dirección del puntero en 5. También, se utiliza el operador `*` para acceder a la dirección del primer elemento más 5, de ahí que se utilicen los paréntesis.

### 19. ¿En qué caso es conveniente usar el operador `->` en punteros y por qué es beneficioso?



### 20. ¿Cuál es la manera de implementar punteros dobles, triples, etc? Brinde un ejemplo de en qué caso sería beneficioso usar esta implementación.

### 21. ¿Qué es el puntero `this` en C++?

### 22. ¿Qué es un puntero `nullptr`?

### 23. ¿Qué es una función prototipo?

### 24. ¿Dónde y cómo se guardan las variables que se crean en C++? Explique la diferencia entre el almacenamiento de variables locales y globales.

### 25. Investigue qué es un memory leak.

### 26. ¿Qué es memoria dinámica?

### 27. ¿Qué es memoria estática?


## Conversión de Unidades

## Calculadora de Estadísticas y Búsqueda en un Arreglo
