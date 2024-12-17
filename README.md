# StaticLibraryProject

Dieses Projekt erstellt eine **statische Bibliothek**, führt Tests aus und installiert die Bibliothek samt Header-Dateien in die Standardverzeichnisse unter Ubuntu mithilfe von **CMake**. Ein Beispielprogramm demonstriert, wie die installierte Bibliothek verwendet wird.

---

## Projektstruktur

Das Projekt ist in folgende Verzeichnisse aufgeteilt:

```
StaticLibraryProject/
│-- CMakeLists.txt             # Haupt-CMake-Konfigurationsdatei
│-- include/
│   └── StaticLib.h            # Header-Datei der Bibliothek
│-- src/
│   └── StaticLib.cpp          # Implementierung der Bibliothek
│-- tests/
│   │-- CMakeLists.txt         # CMake für Tests
│   └── test_staticlib.cpp     # Testdatei für die Library
│-- example/
│   │-- CMakeLists.txt         # Eigenes CMake für das Beispielprogramm
│   └── main.cpp               # Beispiel zur Nutzung der installierten Bibliothek
```

---

## Dateien und deren Aufgaben

### 1. **include/StaticLib.h** - Header-Datei
Definiert die Schnittstelle der statischen Bibliothek:

```cpp
#ifndef STATIC_LIB_H
#define STATIC_LIB_H

class StaticLib {
public:
    void sayHello() const;
};

#endif // STATIC_LIB_H
```

---

### 2. **src/StaticLib.cpp** - Implementierung der Bibliothek
Implementiert die Methode der Bibliothek:

```cpp
#include "StaticLib.h"
#include <iostream>

void StaticLib::sayHello() const {
    std::cout << "Hello from Static Library!" << std::endl;
}
```

---

### 3. **tests/test_staticlib.cpp** - Testdatei
Testet die Funktionalität der Bibliothek:

```cpp
#include "StaticLib.h"
#include <cassert>
#include <iostream>

int main() {
    StaticLib lib;
    lib.sayHello();
    std::cout << "Test passed: sayHello() works correctly." << std::endl;
    return 0;
}
```

---

### 4. **Haupt-CMakeLists.txt** - Konfiguration des Builds

```cmake
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
```

---

### 5. **example/CMakeLists.txt** - Beispielprojekt
Verwendet die installierte Bibliothek:

```cmake
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
```

---

### 6. **example/main.cpp** - Beispielcode
Demonstriert die Verwendung der Bibliothek:

```cpp
#include "StaticLib.h"

int main() {
    StaticLib lib;
    lib.sayHello();
    return 0;
}
```

---

## Schritte zur Erstellung und Installation

### 1. **Projekt konfigurieren und bauen**
Erstelle ein Build-Verzeichnis und führe CMake aus, um das Projekt zu bauen:

```bash
cmake -B build
cmake --build build/
```

### 2. **Tests ausführen**
Führe die Tests aus, um die Bibliothek zu überprüfen:

```bash
ctest --test-dir build/
```

**Erwartete Ausgabe:**
```plaintext
Hello from Static Library!
Test passed: sayHello() works correctly.
```

### 3. **Bibliothek installieren**
Installiere die Bibliothek und die Header-Dateien in die Standardverzeichnisse:

```bash
sudo cmake --install build/
```

- Die statische Bibliothek wird nach `/usr/local/lib/libStaticLib.a` installiert.
- Die Header-Dateien werden nach `/usr/local/include` installiert.

---

## Beispielprogramm erstellen (mit installierter Bibliothek)

### 1. **Beispielprojekt konfigurieren und bauen**
Wechsle in das `example`-Verzeichnis und baue das Projekt:

```bash
cd ../example
cmake -B build && cmake --build build/
```

### 2. **Beispiel ausführen**
Starte das Beispielprogramm:

```bash
./StaticLibExample
```

**Erwartete Ausgabe:**
```plaintext
Hello from Static Library!
```

---

## Fazit

Dieses Projekt:
1. Erstellt eine **statische Bibliothek** zur Wiederverwendung.
2. Führt Tests automatisch nach dem Build-Prozess aus.
3. Installiert die Bibliothek und die Header-Dateien in **Systemverzeichnisse** (`/usr/local/lib` und `/usr/local/include`).
4. Zeigt mit einem Beispielprojekt, wie die Bibliothek in anderen Anwendungen verwendet werden kann.

---

Mit diesen Schritten kannst du deine eigene statische Bibliothek erstellen, testen und einfach wiederverwenden!

---

## Autor

[MaxClerkwell](https://github.com/MaxClerkwell)
