# Definir compilador y banderas
CC = g++
CFLAGS = -Wall

# Source files
SRC1 = src/main1.cpp src/programa1.cpp
SRC2 = src/main2.cpp src/programa2.cpp

# Directorio build
BUILD_DIR = build

# Archivos ejecutables 
TARGET1 = $(BUILD_DIR)/programa1.exe
TARGET2 = $(BUILD_DIR)/programa2.exe

# Header files
HEADER1 = src/programa1.hpp
HEADER2 = src/programa2.hpp

# Argumentos para programa2.exe
ARGS2 = 1 2 3 5 10 12 15

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
all: $(TARGET1) $(TARGET2)
	./$(TARGET1)
	./$(TARGET2) $(ARGS2)

# Construccion de directorio build
$(BUILD_DIR):
	$(MKDIR)

$(TARGET1): $(BUILD_DIR) $(SRC1) $(HEADER1)
	$(CC) $(CFLAGS) -o ./$(TARGET1) $(SRC1)

$(TARGET2): $(BUILD_DIR) $(SRC2) $(HEADER2)
	$(CC) $(CFLAGS) -o ./$(TARGET2) $(SRC2)

# Comando para correr los ejecutables
run:
	./$(TARGET1)
	./$(TARGET2) $(ARGS2)

# Comando para eliminar los ejecutables
clean:
	$(RM) ./$(TARGET1)
	$(RM) ./$(TARGET2)
