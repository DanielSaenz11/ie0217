
# Agregar los ejecutables de pruebas
add_executable(CircuitosTests CircuitosTests.cpp)
add_executable(ComponenteTests ComponenteTests.cpp)
add_executable(InventarioTests InventarioTests.cpp)
add_executable(InventarioFunctionalTests InventarioFunctionalTests.cpp)

# Enlazar GoogleTest y la biblioteca del proyecto
target_link_libraries(CircuitosTests gtest gtest_main inventory_circuit_lib)
target_link_libraries(InventarioTests gtest gtest_main inventory_circuit_lib)
target_link_libraries(InventarioFunctionalTests gtest gtest_main inventory_circuit_lib)
target_link_libraries(ComponenteTests gtest gtest_main inventory_circuit_lib)

# Agregar directorio de cabeceras
target_include_directories(CircuitosTests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(InventarioTests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(InventarioFunctionalTests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(ComponenteTests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Agregar pruebas a CMake
add_test(NAME CircuitosTests COMMAND CircuitosTests)
add_test(NAME ComponenteTests COMMAND ComponenteTests)
add_test(NAME InventarioTests COMMAND InventarioTests)
add_test(NAME InventarioFunctionalTests COMMAND InventarioFunctionalTests)
