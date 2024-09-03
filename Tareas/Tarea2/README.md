# Tarea 2

Esta corresponde a la _Tarea 1_ del curso IE-0217, en la cual se tratan los principios del lenguaje de programación C++. La asignación está dividida en las siguientes partes:

1) Modo de uso
2) Preguntas teóricas
3) Sistema de Gestión de Tienda en Línea

## Modo de uso

## Preguntas teóricas

### 1. ¿Qué es la programación orientada a objetos y cuáles son sus principios fundamentales?

El concepto de la programación orientada a objetos radica en que es un paradigma de programación, enfocado en la creación de __clases__ y __objetos__, los cuales contienen atributos (datos) y métodos (funciones) para operar sobre ellos. Esta organización en objetos facilita la organización y mantenimiento de código, pues está rodeando al objeto como tal.

La programación orientada a objetos (OOP) posee 4 pilares fundamentales:
1) __Encapsulamiento:__ Agrupación de datos y métodos dentro del objeto, para el cual se ocultan algunos datos. Lo necesario para interactuar con el objeto de la clase se expone por medio de métodos y atributos _públicos_.

2) __Abstracción__: Se ocultan los detalles de la implementación

# PENDIENTE

3) __Herencia__: Permite la reutilización de código previo (clase padre), dentro de una clase hija. La nueva clase está basada en la previa, pero se pueden sobreescribir elementos dentro de esta. 

4) __Polimorfismo__:

### 2. Mencione y explique al menos tres problemas clásicos de programación que POO es capaz de resolver.

### 3. Describa el concepto de polimorfismo y brinde un ejemplo de su implementación en POO.

El __polimorfismo__ en la programación orientada a objetos corresponde a uno de sus pilares fundamentales. Existen dos tipos principales de polimorfismo en C++: en tiempo de compilación y en tiempo de ejecución.

En tiempo de compilación, se puede tener polimorfimo al realizar una sobrecarga de función en métodos de una clase. Asimismo, funciona con sobrecarga de operadores. Se llaman de esta manera, pues durante la compilación, el compilador determina cuál definición de función corresponde a las llamadas de estas, en el caso de sobrecarga de funciones.

En tiempo de ejecución, el polimorfismo se da por medio de sobreescritura de funciones (_overriding_). Consiste en ejecutar métodos de diferentes clases derivadas como objetos de la misma clase base, de esta forma, se tienen diferentes comportamientos según el tipo de objeto. Se suelen utilizar _miembros virtuales_ en este caso, si se desea que al tener un puntero de la clase base que apunte a un objeto derivado, se ejecute el método de la clase derivada.

Un ejemplo para este último caso corresponde al siguiente:

```
#include <iostream>
using namespace std;

// Declaracion de clase base
class Base {

public:
    // funcion miembro virtual
    virtual void display()
    {
        cout << "Funcion virtual base" << endl;
    }

    void print()
    {
        cout << "Funcion base" << endl;
    }
};

// Declaracion de clase derivada
class Derivada : public Base {

public:
    void display()
    {
        cout << "Funcion en clase Derivada" << endl;
    }

    void print()
    {
        cout << "Funcion en clase Derivada" << endl;
    }
};

int main()
{
    // Puntero de clase Base
    Base* base;

    // Instanciar objeto de tipo Derivada
    Derivada derivada;

    // Puntero de clase Base apunta a objeto de Derivada
    base = &derivada;

    // Se ejecuta la funcion de Derivada
    base->display();

    // Se ejecuta la funcion de Base
    base->print();
}
```

Note que al utilizar el puntero a la clase Base que apunta a un objeto de la clase Derivada, se tiene que se ejecutan los métodos sobreescritos en Derivada para las funciones del tipo virtual. Esto es fundamental para aplicar el principio de polimorfismo, pues se pueden tener varias clases derivadas de una misma clase base y al ejecutar los métodos virtuales, se ejecutan sus propias modificaciones. 

### 4. Describa el concepto de abstracción y brinde un ejemplo de su implementación en POO.

### 5. Describa el concepto de encapsulamiento y brinde un ejemplo de su implementación en POO.

### 6. Defina los conceptos de clase, objeto, método y atributo de la programación orientada a objetos y brinde un ejemplo de la vida real (No de programación) que los describa intuitivamente.

### 7. Mencione qué elementos tiene el “boilerplate” de una clase y explique cada uno.

### 8. ¿Qué es el constructor de una clase? ¿Para qué sirve?

### 9. ¿Qué es instanciar un objeto en el contexto de POO? ¿Para qué sirve?

### 10. ¿Cuáles son las diferencias entre los especificadores de acceso públicos, privados y protegidos?

Los especificadores de acceso o _access specifiers_ son utilizados dentro de las clases para determinar la visibilidad y accesibilidad de los miembros. Como su nombre lo indica, son utilizados para especificar en dónde se pueden utilizar los miembros.

Primero, el __acceso público__ permite que los miembros sean utilizados desde cualquier parte del programa, no necesariamente dentro de la clase.

Luego, el __acceso privado__ proporciona una accesibilidad limitada al ámbito de la clase. No pueden ser utilizados fuera de esta.

Finalmente, el __acceso protegido__ permite que sean accedidos desde dentro de la clase y desde clases derivadas, pero no fuera de la clase.

La excepción a los casos de miembros con acceso privado y protegido son las clases y funciones amigas que se describen en una pregunta posterior.

### 11. ¿Qué es el destructor de una clase y para qué aplicaciones es conveniente usarlo?

El destructor de una clase consiste en un método o función miembro que se ejecuta de forma automática cuando el tiempo de vida de un objeto de la clase acaba; es decir, cuando se elimina con `delete` o finaliza el programa, por mencionar algunos casos.

Se utiliza principalmente cuando un objeto adquirió memoria dinámica y se debe liberar al eliminarse el objeto. Además, si se abren archivos, en el destructor se ejecuta el comando de cerrado.

El destructor se declara de la siguiente forma:
```
class Clase {
    public:
        // Constructor
        Clase();

        // Destructor
        ~Archivo();
};
```

### 12. Explique qué es la sobrecarga de operadores y proporcione un ejemplo de cómo se implementa en C++.

### 13. ¿Qué es la herencia en POO?

### 14. Mencione las diferencias entre la herencia pública, privada o protegida de una clase, qué sucede al heredar cada tipo.

Como se menciona en el enunciado, existen 3 tipos principales de herencia: pública (_public_), privada (_private_) y protegida (_protected_). Al declarar una clase, se indica herencia de la siguiente forma:
```
class Derived : <tipoHerencia> Base;
```

Entonces, la __herencia pública__ implica los miembros públicos permanecen públicos, los miembros protegidos permanecen protegidos y los miembros privados no se heredan.

La __herencia protegida__ consiste en que los miembros públicos y protegidos pasan a ser protegidos en la clase derivada. Los miembros privados mantienen su comportamiento de no herencia.

Finalmente, en la __herencia privada__ se heredan los miembros públicos y privados de la clase base, pero pasan a ser miembros privados dentro de esta. De igual manera, los miembros privados de la clase base no se heredan.


### 15. Observe el siguiente fragmento de código:

```
#include <iostream>

class Base {
    private:
        int primera;
    protected:
        int segunda;
    public:
        int tercera;
        Base() : primera(1), segunda(2), tercera(3) {}
};

class Derived : public Base {
    private:
        int cuarta;
    protected:
        int quinta;
    public:
        int sexta;
        Derived() : cuarta(4), quinta(5), sexta(6) {}
};
```

Considerando que existen seis variables en el código (primera, segunda, tercera, cuarta, quinta y sexta), desde el main del programa:
- A cuáles de estas variables puede acceder un objeto instanciado de la clase Base, a cuales no puede acceder y por qué.
- A cuáles de estas variables puede acceder un objeto instanciado de la clase Derived, a cuales no puede acceder y por qué.

### 16. ¿Qué es una clase amiga y para qué se usa? ¿Cúal es la manera de definirla?

Las clases amigas corresponden a clases que pueden acceder a los miembros _protected_ y _private_ de la clase en cuestión; es decir, tienen acceso a los miembros que sólo se pueden acceder dentro de la clase.

Su principal uso consiste en la colaboración entre clases, cuando se requiere que una clase acceda a atributos o métodos privados o protegidos.

La manera de definir una clase amiga se muestra a continuación:

```
// Se coloca la declaracion de la clase amiga antes para que el compilador sepa que existe y se va a definir despues
class ClaseA;

class ClaseB {
    public:
        void mostrarDatosA(ClaseA &a) {
            cout << "Privado de A: " << a.datoPrivado << endl;
        }
};

class ClaseA {
    private:
        // Miembro privado que tiene acceso ClaseB
        int privado;
    
    public:
        // Constructor
        ClaseA(int valor) : privado(valor) {}

        // Declaracion de ClaseB como amiga de ClaseA
        friend class ClaseB;
};
```

Entonces, en el ejemplo anterior, se muestra que la `ClaseA` coloca a `ClaseB` como clase amiga. Por lo tanto, en la `ClaseB` se pueden acceder los miembros privados de la `ClaseA`.

### 17. ¿Qué es una función amiga y para qué se usa? ¿Cúal es la manera de definirla?

Las funciones amigas son funciones que no pertenecen a ninguna clase, pero están colocadas dentro de la clase de interés con el keyword `friend`, de tal forma que tienen acceso a los atributos privados y protegidos de la clase. Su importancia radica en que, así, no se exponen los datos públicamente, únicamente la función amiga tiene acceso.

La forma de definir una función amiga se muestra a continuación:
```
// Declaracion de ClaseA
class ClaseA {
    private:
        int privado;
    
    public:
        // Constructor
        ClaseA(int valor) : privado(valor) {}

        // Declaracion de funcion amiga
        friend void imprimir(const ClaseA &a);
};

void imprimir(const ClaseA &a) {
    cout << "Privado: " << a.privado << endl;
}
```

La función `imprimir()` puede acceder a los miembros privados de `ClaseA`.

### 18. Explique la importancia de los métodos virtuales en C++ y cómo se utilizan en la implementación de polimorfismo.

## Sistema de Gestión de Tienda en Línea