cmake_minimum_required(VERSION 3.10)
project(IMC-tests)

set(CMAKE_CXX_STANDARD 17)

# Agrega Google Test como subdirectorio
#add_subdirectory(googletest)

# Archivos fuente
add_library(imc_lib IMC.cpp)

# Configuración de Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Agrega el ejecutable para las pruebas
add_executable(test_imc test/test_IMC.cpp)

# Incluye los encabezados de Google Test
include_directories(${gtest_SOURCE_DIR}/include)

# Enlaza las bibliotecas necesarias
target_link_libraries(test_imc imc_lib ${GTEST_LIBRARIES} pthread)

# Agrega un comando para ejecutar las pruebas
add_test(NAME test_imc COMMAND test_imc)
