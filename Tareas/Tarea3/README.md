# Tarea 3

Esta corresponde a la _Tarea 3_ del curso IE-0217, en la cual se trata la implementación de . La asignación está dividida en tres partes:



## Modo de uso

## Parte teórica

En esta sección, se van a resolver las preguntas teóricas de la parte inicial de la tarea 3.

### 1. Explique cada sección del nivel de usuario de la memoria (Text, Heap, Stack, etc..) ¿Cuáles de estas secciones son de memoria dinámica?

El nivel de usuario de la memoria se divide en las siguientes secciones:

- __Text segment__: Esta contiene el código ejecutable del programa, por lo que, abarca las instrucciones compiladas y código de bibliotecas que se enlazan al programa. Además, no corresponde a una parte de memoria dinámica, pues es memoria estática que no cambia en el tiempo de ejecución.

- __Initialized Data segment__: Contiene las variables globales y estáticas __inicializadas__, las cuales permanecen en memoria durante el tiempo de ejecución. Corresponde a una sección estática, definida en la compilación.

- __BSS (Block Started by Symbol)__: Abarca las variables globales y estáticas que no han sido inicializadas por el programador. Estas permanecen en memoria durante toda la ejecución del programa.  

- __Heap__: Es la región de la memoria del programa utilizada para la memoria dinámica durante la ejecución. El tamaño de este varía durante la ejecución del programa, pues el programador puede solicitar o liberar memoria del heap. Por lo descrito anteriormente, sí es de memoria dinámica. Permite que implementar soluciones tales que, su tamaño no se conoce antes de ejecutar el código.

- __Stack__: En esta sección, se almacena las variables locales y se siguen las llamadas de las funciones durante la ejecución del programa. Al crear una función, se crea un _stack frame_ con las variables locales de la función y cuando se termina la ejecución se libera, por ejemplo. A pesar de que cambie su tamaño durante la ejecución, no es memoria dinámica, pues la administración de memoria es automáticamente manejada.

Tomado de [Memory Layout of C++ Programs - GeeksForGeeks](https://www.geeksforgeeks.org/memory-layout-of-c-program/)

### 2. Observe el siguiente fragmento de código:

```
#include <iostream>

int globalVar = 42;

int main() {
    static int staticVar = 100;
    int localVar = 10;
    int* dynamicVar = new int(5);
    
    delete dynamicVar;
    
    return 0;
}
```

Considerando que existen cuatro variables en el código (`globalVar`, `staticVar`, `localVar` y `dynamicVar`), mencione en qué sección de la memoria se almacena cada variable y explique el porqué.
---

En primer lugar, se tiene la variable en el código `globalVar`, como se observa esta corresponde a una variable global inicializada con el valor de 42. Por lo tanto, pertenece a la sección de memoria __Initialized Data Segment__, pues como se describió en la pregunta anterior, acá se almacenan variables globales y estáticas inicializadas.

En segundo lugar, `staticVar` consiste en una variable de tipo estática definida dentro de _main()_. Las variables estáticas poseen su valor durante toda la ejecución del programa, por lo tanto, se almacenan en el __Initialized Data Segment__.

En tercer lugar, `localVar`, la cual como su nombre lo indica corresponde a una variable local dentro de _main()_. Entonces, las variables locales se almacenan en el __stack__ en un _stack frame_, que se destruye al terminar la ejecución de la función.

En cuarto lugar, `dynamicVar`, consiste en una variable puntero reservada a partir de memoria dinámica del __heap__. La memoria a la que apunta el puntero proviene del heap, pues se utilizó el keyword `new` para reservar memoria de allí y se tiene que liberar por medio de `delete`. Sin embargo, el puntero como tal se almacena en el stack.


### 3. ¿Cuál es la diferencia entre memoria dinámica y memoria estática? Brinde un ejemplo de qué tipos de variables se almacenan en cada tipo.

Primero, se va a describir la __memoria estática__. Esta es asignada durante el tiempo de compilación. Además, las variables de este tipo viven durante todo el tiempo de ejecución del programa y su administración es realizada de forma automática por el sistema operativo. La memoria estática (almacenada en _data segment_) corresponde a las variables globales (fuera de _main()_) y estáticas (keyword `static`), tanto inicializadas como no inicializadas.

Ahora, en cuanto a la __memoria dinámica__, se tiene que esta se asigna durante el tiempo de ejecución del programa. El ciclo de vida de las variables dinámicas consiste desde que fueron reservadas hasta que se libera la memoria (importante resaltar la liberación manual de memoria para evitar _memory leaks_). La memoria dinámica se almacena en el _heap_. En cuanto a los ejemplos de variables que almacena, se tienen arreglos de datos dinámicos que se puede requerir cambiar su tamaño durante la ejecución y objetos dinámicos de una clase.


### 4. ¿Cómo se accede a la memoria dinámica del heap? Brinde un ejemplo programado de cómo guardar un valor en una posición de memoria ubicada ahí.

El proceso de acceder a memoria del __heap__ se realiza por medio de punteros. En el ejemplo programado a continuación se muestra la reservación dinámica de un entero en el _heap_ con el keyword `new`, en el cual la dirección de esa memoria se almacena en el puntero entero `dynamicVar`. Luego, se le asigna un valor por medio del operador de desreferencia `*` al puntero. Finalmente, se debe liberar la memoria reservada por medio del keyword `delete`.

```
#include <iostream>
using namespace std;

int main() {
    // Asignación dinámica de un entero en el heap
    int dynamicVar = new int;

    // Guardar un valor en la posición reservada
    *dynamicVar = 1; // Uso de * para desreferenciar el valor

    delete dynamicVar;

    return 0;
}
```


### 5. ¿Por qué es importante liberar la memoria asignada dinámicamente cuando ya no se esté utilizando?

La memoria asignada dinámicamente del __heap__ debe ser liberada cuando ya no se esté utilizando, o al menos al terminar la ejecución del programa. Se describen algunas de las razones que determinan la importancia de la liberación de memoria en programas que utilizan memoria dinámica:

- __Memory leaks__: Al reservar memoria dinámica, esta no se libera automáticamente, como en el caso de los demás tipos de memoria. Por lo tanto, es necesario utilizar el keyword `delete` o `free()` para liberar la memoria dinámica asignada previamente. De esta forma, se evitan las fugas de memoria que provoca que el programa consuma más memoria de la que debería y puede agotar la memoria eventualmente, lo cual afecta el rendimiento del sistema, en general.

- __Sobrecarga del heap__: Si se satura la memoria que ocupa el programa, se puede afectar el funcionamiento de otros procesos en el sistema, pues se reduce la cantidad de memoria disponible para ellos también (especialmente en sistemas con recursos limitados como sistemas embebidos). Además, el _heap_ posee una fragmentación (por ende es más lento comparado con otros tipos de memoria), por lo que, si la memoria no se libera, aunque haya memoria total disponible, puede no haber un bloque continuo del tamaño requerido, lo cual dificulta la reservación de memoria posterior.


### 6. ¿Para que se utilizan las funciones `malloc`, `calloc` y `realloc`? ¿Qué parámetros recibe cada una?

Las 3 funciones mencionadas son utilizadas en el manejo de memoria dinámica del __heap__ pertenecientes a la biblioteca estándar de C. A continuación, se describen las características de cada una:

- `malloc()`: Se utiliza para asignar un bloque de código de un tamaño específico. Resulta importante mencionar que no inicializa la memoria con un valor, entonces puede contener información basura. Observe en el ejemplo debajo, que `malloc()` recibe el tamaño de memoria a asignar en bytes. Usualmente, se utiliza la función integrada `sizeof()` para determinar el tamaño del tipo de dato que se desea reservar memoria. Además, la función retorna un puntero de tipo `void` a la memoria recién asignada, por lo que, se utiliza _casting_ para pasar el puntero al tipo de dato requerido. En caso de no haber memoria suficiente, se retorna `NULL`.

```
// Sintaxis: void* malloc(size)
int *ptr = (int*)malloc(sizeof(int));
```

- `calloc()`: Es utilizado para asignar memoria para un _array_ de elementos, de tal forma que, todos ellos se inicializan con un valor de 0. Al igual que `malloc()`, la función también retorna un puntero de tipo `void` a la memoria recién reservada y retorna `NULL` en caso de error. Además, recibe la cantidad de elementos que va a contener el arreglo y el tamaño de un elemento del arreglo en bytes.

```
// Sintaxis: void* calloc(num_elementos, size_elemento);
int *array = (int*)calloc(5, sizeof(int));
```

- `realloc()`: Esta función es utilizada para redimensionar un bloque de memoria reservado previamente. Si el nuevo tamaño es mayor, se mantiene el contenido y se agrega nuevo espacio para memoria. En caso de que sea menor, se descarta el contenido excedente. La función recibe el puntero al bloque de memoria antiguo y el nuevo tamaño requerido en bytes. Además, retorna un puntero de tipo `void`, que apunta a la dirección de memoria resultante. Si no se pudo redimensionar, devuelve `NULL` y no se modifica la memoria anterior. 

```
int *array = (int*)malloc(5 * sizeof(int));

// Sintaxis: void* realloc(void *ptr, size_nuevo);
array = (int*)realloc(array, 10 * sizeof(int));
```

### 7. Mencione las diferencias entre el uso de `free()` y `delete`. ¿En qué contexto se utilizaría cada uno?

Ambas funciones son utilizadas para la liberación de memoria dinámica de un programa de C++, pues como se ha mencionado en el transcurso de las respuestas a las preguntas de la sección teórica, la memoria dinámica debe ser liberada manualmente por el programador para evitar fugas de memoria.

- `free()`: Proviene del lenguaje C, por lo que, es utilizada para liberar memoria que fue asignada con `malloc()`, `calloc()` o `realloc()`. Una diferencia importante es que si se están liberando objetos (propios de C++), no se llama al destructor de estos. 

- `delete`: Originario de C++, entonces sí es compatible con las implementaciones de este lenguaje respecto a C (keyword `new`). Por lo tanto, si se asignó memoria con `new`, al liberar la memoria con `delete`, se llama también al destructor de la clase del objeto. Cuando se va a liberar la memoria de un arreglo dinámico, se utiliza el comando `delete[]`.


### 8. Explique la diferencia entre `new` y `malloc()` en C++. ¿Cuándo deberı́a utilizar uno sobre el otro?

Las funciones `new` y `malloc()` son utilizadas para la asignación de memoria dinámica del heap. Su principal diferencia radica en que `malloc()` corresponde a una función perteneciente a la _standard library_ de C, mientras que, `new` fue implementada propiamente para C++.

Entonces, partiendo de lo anterior, se tiene que `new` es compatible con la programación orientada a objetos y entonces al crear un objeto con este, se inicia el constructor del mismo. En el caso de `malloc()` sólo se asigna la memoria.

Las sintaxis de ambos son un poco distintas, un ejemplo de su uso para inicializar un array con 10 elementos, se muestra a continuación:

```
// Uso de new
int *arr = new int[10]; // Array de 10 elementos

// Uso de malloc()
int *arr = (int*)malloc(10 * sizeof(int))
```

Por lo tanto, cuando se trabaja con programación orientada a objetos, es necesario utilizar `new` para reservar la memoria del heap y `delete`para liberarla. En el caso de asignación de arreglos, se pueden utilizar ambos con sus sintaxis específicas. Además, se presentan diferencias en cuanto a las excepciones que se devuelven al no poder asignar memoria. `new` genera una excepción de `std::bad_alloc` mientras que `malloc()` devuelve `NULL`.

Usualmente se utiliza `malloc()` cuando se busca la compatibilidad con C. Sin embargo, `new` es preferible en la mayoría de casos.


### 9. Explique el concepto de punteros inteligentes (smart pointers) y proporcione ejemplos de su uso.

Los _smart pointers_ fueron implementados en C++, para facilitar el manejo de memoria dinámica, pues evitan fugas de memoria y __dangling pointers__. Este tipo de punteros maneja automáticamente la liberación de la memoria reservada del heap. Esto se debe a que, los punteros inteligentes, en términos sencillos, son clases que rodean punteros.

# Pendiente


### 10. Mencione qué es un algoritmo y explique qué características básicas debería tener.

El concepto de algoritmo está dado como un conjunto de instrucciones secuenciales finitas que son utilizadas para implementar la solución a un problema o realizar una acción en específico.

La idea de los algoritmos es que poseen una __entrada__ (_input_) y una __salida__ (_output_). La entrada consiste en los datos sobre los que se ejecuta el algoritmo, mientras que, la salida es el resultado de la operación realizada por el algoritmo.

Además, un algoritmo tiene una __complejidad__ asociada, la cual describe la eficiencia en la ejecución del algoritmo. Este parámetro se divide en complejidad temporal (cuánto tarda) y espacial (cuánta memoria utiliza).

A partir de lo anterior, se tiene que los algoritmos deben ser claros (implementación definida), generales (pueden ser realizados en cualquier lenguaje de programación) y correctos (para cada conjunto de datos producen la salida esperada).

Obtenido de: [Introduction to Algorithms - GeeksForGeeks](https://www.geeksforgeeks.org/introduction-to-algorithms/).


### 11. ¿Qué es la complejidad y eficiencia de un algoritmo? ¿De qué manera se miden?

La complejidad y eficiencia de un algoritmo corresponden a la cantidad de tiempo y espacio que se utiliza durante el tiempo de ejecución. Entre menores recursos se utilicen, mejor algoritmo.

Entonces, la complejidad temporal se mide respecto a la cantidad de operaciones que se realizan, mientras que, el espacio se refiere a la memoria empleada. Además, la complejidad de un algoritmo usualmente depende de la entrada, a medida que crece, se refleja en el tiempo y espacio ocupado.

Para la medición de la complejidad de los algoritmos, se utiliza comúnmente la notación __Big-O__. Esta representa la peor complejidad temporal y espacial que puede alcanzar un algoritmo (comportamiento asintótico). También existe la notación para el límite inferior de recursos que se llama notación __omega__, y la notación __theta__ representa la complejidad promedio de un algoritmo.


### 12. ¿Cuál es la diferencia entre las estructuras de datos lineales y no-lineales? Mencione dos ejemplos de cada una.

Las estructuras de datos lineales y no lineales difieren en la forma en la que organizan los elementos y permiten accederlos.

- __Estructuras de datos lineales__: Como su nombre lo indica, se organizan de forma secuencial. Para recorrerlos, se tiene inicia en el primer elemento hasta el final. Como ejemplos, se tienen los _arreglos_ y _listas enlazadas_, pues estos poseen una clara relación entre el elemento anterior, el actual y el siguiente.

- __Estructuras de datos no lineales__: La principal característica de este tipo de estructuras es que los elementos no se organizan de forma secuencial (al contrario que los lineales). Por lo tanto, los elementos que los componen pueden tener varias relaciones con otros elementos; puede ser de tipo jerárquica, por ejemplo. Dos ejemplos de estas estructuras consisten en los árboles y grafos. Note que ambos se pueden recorrer de distintas formas.



### 13. Explique cómo funciona la estructura Stack.




### 14. Explique cómo funciona la estructura Queue.


### 15. Explique cómo funciona la estructura Lista Enlazada.


### 16. Explique cómo funciona la estructura Árbol. ¿Qué características presenta esta estructura?


### 17. Explique los tipos de recorridos que se le pueden aplicar a un árbol.


### 18. ¿Cuál es la diferencia entre un árbol y un árbol binario? Mencione y explique tres tipos de árboles binarios.


