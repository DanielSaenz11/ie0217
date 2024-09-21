# Variables
CXX = g++ # Compilador
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 # Flags: versión, warnings
SRCDIR = src # Directorio de código fuente (Source)
OBJDIR = obj # Directorio con los archivos objeto resultado de la compilación
BINDIR = bin # Directorio con los archivos binarios ejecutables
TARGET = $(BINDIR)/text_processor.exe # Target file

# Archivos fuente y objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Reglas
all: $(TARGET)

# Compilar TARGET: Requiere a los OBJECTS como dependencias
$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^


# Compilar archivos objeto: Se enlazan entre sí para producir el ejecutable y que posea todas las referencias resueltas
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para eliminar los archivos objeto y TARGET
clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(TARGET)

# Ejecución del programa con file1.txt
run: $(TARGET)
	./$(TARGET) data/file1.txt

# Regla .PHONY: No quiere dependencias
.PHONY: all clean run
