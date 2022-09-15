cmake_minimum_required(VERSION 3.12)
project(noc LANGUAGES CXX)

set_property(TARGET PROPERTY CXX_STANDARD 17)

# Setup for conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Modules of systemc libraries
add_library(AXI4 STATIC AXI4.cpp)
add_library(router STATIC router.cpp AXI4)

# sc_main
add_executable(noc main.cpp)

# Linkage of systemc modules and sc_main
target_link_libraries(noc router ${CONAN_LIBS})
