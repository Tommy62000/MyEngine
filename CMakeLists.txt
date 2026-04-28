cmake_minimum_required(VERSION 3.16)
project(MyEngine)

set(CMAKE_CXX_STANDARD 17)

# GLFW
add_subdirectory(external/glfw)

# GLAD
add_library(glad external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

# Executable
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(MyEngine ${SOURCES})

# Include dirs
target_include_directories(MyEngine PRIVATE
    external/glad/include
    external/glfw/include
    ${CMAKE_SOURCE_DIR}/src
)

# Link
target_link_libraries(MyEngine
    glfw
    glad
)

# Linux fix
if(UNIX AND NOT APPLE)
    target_link_libraries(MyEngine dl)
endif()