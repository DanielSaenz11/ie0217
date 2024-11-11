# Definir compilador y banderas
CC = g++
CFLAGS = -Wall -std=c++20

# Source directories
SRC_DIR1 = ./src/Ejercicio1
SRC_DIR2 = ./src/Ejercicio2

# Source files
SRC1 = $(SRC_DIR1)/main.cpp $(SRC_DIR1)/solicitudes.cpp
SRC2 = $(SRC_DIR2)/main.cpp $(SRC_DIR2)/DataProcessor.cpp

# Header files
HEADER1 = $(SRC_DIR1)/solicitudes.hpp
HEADER2 = $(SRC_DIR2)/DataProcessor.hpp

# Directorio build
BUILD_DIR = build

# Archivos ejecutables 
TARGET1 = $(BUILD_DIR)/solicitudes.exe
TARGET2 = $(BUILD_DIR)/data.exe

# Detectar el sistema operativo para comando de clean
ifeq ($(OS),Windows_NT)
    RM = if exist $(subst /,\,$(TARGET1)) del $(subst /,\,$(TARGET1)) & if exist $(subst /,\,$(TARGET2)) del $(subst /,\,$(TARGET2))
	MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
# Comandos para Linux
    RM = rm $(TARGET1) $(TARGET2)
	MKDIR = mkdir -p $(BUILD_DIR)
endif

# Ejecución de todos los targets
all: $(TARGET1) $(TARGET2)
	./$(TARGET1)
	./$(TARGET2)

# Construccion de directorio build
$(BUILD_DIR):
	$(MKDIR)

# Programa 1
$(TARGET1): $(BUILD_DIR) $(SRC1) $(HEADER1)
	$(CC) $(CFLAGS) -o ./$(TARGET1) $(SRC1) -pthread

# Programa 2
$(TARGET2): $(BUILD_DIR) $(SRC2) $(HEADER2)
	$(CC) $(CFLAGS) -o ./$(TARGET2) $(SRC2)

# Comando para correr el ejecutable del Ejercicio1
run1:
	./$(TARGET1)

# Comando para correr el ejecutable del Ejercicio2
run2:
	./$(TARGET2)

# Comando para eliminar los ejecutables
clean:
	$(RM)
