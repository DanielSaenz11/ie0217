# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(InventoryCircuitProject)

# Configurar a C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Agregar opciones de compilación para cobertura de código
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")

# Incluir el directorio include para los header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Agregar los archivos fuente del proyecto
set(SOURCES
    src/Circuitos.cpp
    src/Componente.cpp
    src/Inventario.cpp
)

# Crear la biblioteca compartida para el proyecto
add_library(inventory_circuit_lib ${SOURCES})

# Traer GTest del repositorio de origen
add_subdirectory(googletest)

# Incluir directorios de GoogleTest y src
include_directories(googletest/googletest/include src)

# Habilitar las pruebas
enable_testing()

# Agregar el subdirectorio de tests
add_subdirectory(tests)
