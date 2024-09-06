# Definir compilador y banderas
CC = g++
CFLAGS = -Wall -std=c++11

# Source files
SRC = src/main.cpp src/Producto.cpp src/ProductoDigital.cpp src/ProductoFisico.cpp src/Cliente.cpp src/ClienteRegular.cpp src/ClientePremium.cpp src/Tienda.cpp

# Directorio build
BUILD_DIR = build

# Archivos ejecutables 
TARGET = $(BUILD_DIR)/tienda.exe

# Header files
HEADER = src/Producto.hpp src/ProductoDigital.hpp src/ProductoFisico.hpp src/Cliente.hpp src/ClienteRegular.hpp src/ClientePremium.hpp src/Tienda.hpp

# Detectar el sistema operativo para comando de clean
ifeq ($(OS),Windows_NT)
    RM = del
	MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
# Comandos para Linux
    RM = rm
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
	$(RM) ./$(TARGET)
