cmake_minimum_required(VERSION 3.20)

project(xcx VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -------------------------------
# Fetch 3rd party libraries
# -------------------------------
include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.2.1
)

FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(fmt tomlplusplus)

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
    PRIVATE
        fmt::fmt
        tomlplusplus::tomlplusplus
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall -Wextra -Wpedantic
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)
