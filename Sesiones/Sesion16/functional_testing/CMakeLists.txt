# Indicar versión de CMake
cmake_minimum_required(VERSION 3.15)

# Indicar versiónd de compilador
set(CMAKE_CXX_STANDARD 17)

# Nombre del proyecto
project(functional_testing)

# Traer GTest del repositorio de origen
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)

FetchContent_MakeAvailable(googletest)

# Crear el ejecutable y enlazar con gtest y gmock
add_executable(functional_testing test_authentication.cpp)
target_link_libraries(functional_testing gtest_main gmock_main)

enable_testing()
add_test(NAME functional_testing COMMAND functional_testing)
