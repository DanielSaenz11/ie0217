# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(CalculatorProject)

# Agregar los archivos fuente del proyecto
set(SOURCES src/Calculator.cpp)

# Crear el ejecutable para el proyecto principal
add_library(calculator_lib ${SOURCES})

# Traer GTest del repositorio de origen
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)

FetchContent_MakeAvailable(googletest)

# Incluir directorios de GoogleTest
include_directories(googletest/googletest/include)

# Agregar GoogleTest y configurar las pruebas
enable_testing()
add_subdirectory(tests)