cmake_minimum_required(VERSION 3.13)
project(StaticLibraryProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Statische Bibliothek erstellen
add_library(StaticLib STATIC src/StaticLib.cpp)

# Header-Dateien der Bibliothek öffentlich verfügbar machen
target_include_directories(StaticLib PUBLIC include)

# Installationsanweisungen
install(TARGETS StaticLib ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# Tests aktivieren
enable_testing()

# Tests erstellen
add_executable(TestStaticLib tests/test_staticlib.cpp)
target_link_libraries(TestStaticLib StaticLib)
add_test(NAME RunStaticLibTests COMMAND TestStaticLib)