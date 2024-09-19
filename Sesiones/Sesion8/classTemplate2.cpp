/*
Cuando se desea separar la definición de la declaración, se puede utilizar
el siguiente formato:

template <class T>
class ClassName {
    ...

    // Prototipo de funcion
    returnType functionName();
};

// Definición de función
template <class T>
returnType ClassName<T>::functionName() {
    // code
}
*/

template <class T> // Template de clase
class Number {
    // Prototipo de función
    T getnum();
};

// Definición de función
template <class T>
T Number<T>::getnum() {
    // Se especifica el typename T al definir la función
    return num; // Se retorna el valor de num
}