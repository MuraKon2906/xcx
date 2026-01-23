cmake_minimum_required(VERSION 3.20)

project(xcx VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -------------------------------
# 3rd party library
# -------------------------------
add_subdirectory(include/external/fmt)
add_subdirectory(include/external/tomlpp)

# -------------------------------
# Your executable
# -------------------------------
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/setup.cpp
    src/tools.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE fmt::fmt
        tomlplusplus::tomlplusplus
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall -Wextra -Wpedantic
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)
