cmake_minimum_required(VERSION 3.20)

project(xcx VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source files
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/setup.cpp
    src/tools.cpp


)

# Include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# Compiler warnings
target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall -Wextra -Wpedantic
)

# -------------------------------
# INSTALL STEP
# -------------------------------
# Install the executable to a folder in PATH, e.g., /usr/local/bin
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)
