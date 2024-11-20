# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Navn på projektet
project(P1)

# Angiv C-standarden og gør den obligatorisk
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Find alle C-filer i src-mappen og tilføj dem til projektet
file(GLOB SOURCES "src/*.c")

# Opret den eksekverbare fil
add_executable(my_program ${SOURCES})

# Inkluder header-filer fra include-mappen
target_include_directories(my_program PUBLIC "${PROJECT_SOURCE_DIR}/include")

# Aktivér compiler-advarsler for at forbedre kodekvalitet
target_compile_options(my_program PRIVATE -Wall -Wextra -pedantic)

# Debugging-flags for gcc (valgfrit, fjern hvis det ikke er nødvendigt)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(my_program PRIVATE -g)
endif()

