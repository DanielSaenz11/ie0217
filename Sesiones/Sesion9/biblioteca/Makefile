# Makefile para compilar un programa C++ con múltiples archivos y clases
# Nombre del programa de salida
TARGET = gestion_biblioteca.exe

# Objetivo predeterminado
all: $(TARGET)

# Compilador de C++
CXX = g++

# Opciones de compilación: Se indica que se procese todos los warnings y la versión del compilador
CXXFLAGS = -Wall -std=c++11

# Lista de archivos fuente (.cpp)
SOURCES = libro.cpp biblioteca.cpp main.cpp

# Listas de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:.cpp=.exe)

# Regla para compilar los archivos fuente en archivos objeto
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar el programa a partir de los archivos objeto
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para limpiar los archivos generados
.PHONY: clean

# Regla para limpiar los archivos ejecutables creados en el proceso de compilación
clean:
	del $(TARGET) $(OBJECTS)

# Alternativa en Linux
# clean:
# 	rm $(TARGET) $(OBJECTS)
	
