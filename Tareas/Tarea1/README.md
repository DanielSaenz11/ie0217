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

### 11. ¿Qué es el type casting? ¿Cuáles existen? Brinde un ejemplo de cada uno.

### 12. ¿Cuál es la principal diferencia entre un bucle _do-while_ y un bucle _while_?

### 13. Explique por qué es útil y común dividir el código en archivos `.hpp`, `.cpp` y `main.cpp` en C++. Describa el propósito específico de cada tipo de archivo.

### 14. ¿Qué hace la sentencia `goto` y por qué es considerada una mala práctica en la programación moderna? ¿Qué alternativas se pueden usar en su lugar?

### 15. ¿Para qué se utiliza la directiva `#ifndef` y por qué es importante?

### 16. ¿Qué es un puntero y para qué es útil? ¿Cómo se declara e inicializa?

### 17. ¿Cuál es la diferencia entre pasar parámetros por valor, por referencia y por puntero?

### 18. Cuando se usa un puntero para apuntar a un arreglo en C++, ¿a qué valor o dirección apunta inicialmente? Describa cómo sería la forma de acceder a todos los datos de ese arreglo mediante el puntero.

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
