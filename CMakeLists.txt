# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Navn på projektet
project(MyProject)

# Angiv C-standarden
set(CMAKE_C_STANDARD 11)

# Find alle C-filer i src-mappen og tilføj dem til projektet
file(GLOB SOURCES "src/*.c")

# Opret eksekverbar fil
add_executable(my_program ${SOURCES})

# Inkluder header-filer fra include-mappen
target_include_directories(my_program PUBLIC "${PROJECT_SOURCE_DIR}/include")
