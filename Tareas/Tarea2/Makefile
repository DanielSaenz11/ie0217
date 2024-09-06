# Definir compilador y banderas
CC = g++
CFLAGS = -Wall -std=c++11

# Source files
SRC_DIR = ./src
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Producto.cpp $(SRC_DIR)/ProductoDigital.cpp $(SRC_DIR)/ProductoFisico.cpp $(SRC_DIR)/Cliente.cpp $(SRC_DIR)/ClienteRegular.cpp $(SRC_DIR)/ClientePremium.cpp $(SRC_DIR)/Tienda.cpp

# Directorio build
BUILD_DIR = build

# Archivos ejecutables 
TARGET = $(BUILD_DIR)/tienda.exe

# Header files
HEADER = $(SRC_DIR)/Producto.hpp $(SRC_DIR)/ProductoDigital.hpp $(SRC_DIR)/ProductoFisico.hpp $(SRC_DIR)/Cliente.hpp $(SRC_DIR)/ClienteRegular.hpp $(SRC_DIR)/ClientePremium.hpp $(SRC_DIR)/Tienda.hpp

# Detectar el sistema operativo para comando de clean
ifeq ($(OS),Windows_NT)
    RM = if exist $(TARGET) del $(subst /,\,$(TARGET))
	MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
# Comandos para Linux
    RM = rm $(TARGET)
	MKDIR = mkdir -p $(BUILD_DIR)
endif

# Se ejecuta con una lista de numeros predeterminada
all: $(TARGET)
	./$(TARGET)

# Construccion de directorio build
$(BUILD_DIR):
	$(MKDIR)

$(TARGET): $(BUILD_DIR) $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -o ./$(TARGET) $(SRC)

# Comando para correr los ejecutables
run:
	./$(TARGET)

# Comando para eliminar los ejecutables
clean:
	$(RM)
