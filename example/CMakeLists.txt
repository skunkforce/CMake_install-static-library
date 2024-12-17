cmake_minimum_required(VERSION 3.13)
project(StaticLibExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Finde die installierte Bibliothek
find_library(STATIC_LIB StaticLib PATHS /usr/local/lib)

# Beispielprogramm erstellen
add_executable(StaticLibExample main.cpp)

# Bibliothek und Header einbinden
target_include_directories(StaticLibExample PUBLIC /usr/local/include)
target_link_libraries(StaticLibExample ${STATIC_LIB})