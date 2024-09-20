# Makefile para compilar un programa C++ con múltiples archivos y clases
# Nombre del programa de salida
TARGET = gestion_estudiantes.exe

# Compilador de C++
CXX = g++

# Opciones de compilación: Se habilitan todos los warnings y se indica la versión del compilador
CXXFLAGS = -Wall -std=c++11

# Lista de archivos fuente (.cpp)
SOURCES = main.cpp estudiante.cpp

# Lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:.cpp=.exe)

# Regla para compilar los archivos fuente en archivos objeto
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar el programa a partir de los archivos objeto
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para limpiar los archivos ejecutables generados a partir del proceso de compilación
clean:
	del $(TARGET) $(OBJECTS)

# Alternativa en Linux
# clean:
# 	rm $(TARGET) $(OBJECTS)
