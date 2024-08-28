# Laboratorio 3: Sistema de Gestión de Empleados

Este directorio corresponde al Laboratorio 3 realizado el 27 de agosto del 2024, que consiste en un sistema de gestión de empleados, al clasificarlo en forma de empleados de medio tiempo y empleados de tiempo completo. 

## Modo de uso

Para compilar el proyecto, asegúrese de estar en el directorio `./ie0207/Laboratorios/Laboratorio3` propio del presente repositorio y de tener instalado el compilador __g++__. Utilice el siguiente comando: 
```
g++ -o empleados.exe ./src/main.cpp ./src/Empleado.cpp ./src/EmpleadoMedioTiempo.cpp ./src/EmpleadoTiempoCompleto.cpp -std=c++11
```

En este comando, se nombra el archivo ejecutable con el nombre `empleados.exe`. Además, se incluyeron los archivos de código fuente utilizados con extensión `.cpp`. En ciertos dispositivos es necesario agregar el flag `-std=c++11` para indicar la versión del compilador y así, evitar _warnings_.

Para la ejecución del proyecto, después de su compilación, se emplea el comando:
```
./empleados.exe
```

Para eliminar el archivo ejecutable se utiliza el comando a continuación:
```
rm empleados.exe
```

En caso de ejecutar el archivo en un dispositivo con sistema operativo Windows, es necesario cambiar el _slash_ `/` por un backslash `\`. 