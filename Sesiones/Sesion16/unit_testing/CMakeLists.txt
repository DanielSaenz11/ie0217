# Indicar versión de CMake
cmake_minimum_required(VERSION 3.15)

# Indicar versiónd de compilador
set(CMAKE_CXX_STANDARD 17)

# Nombre del proyecto
project(CalculatorTests)

# Traer GTest del repositorio de origen
include(FetchContent)
FetchContent_Declare(
  gtest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)

FetchContent_MakeAvailable(gtest)

# Crear el ejecutable y enlazar con gtest y gmock
add_executable(test_calculator test_calculator.cpp)
target_link_libraries(test_calculator gtest_main)

enable_testing()
add_test(NAME test_calculator COMMAND test_calculator)
