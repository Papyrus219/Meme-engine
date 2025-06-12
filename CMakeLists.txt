cmake_minimum_required(VERSION 3.22)
project(Memengine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SRC src/*cpp)
set(SOURCES ${SRC})

add_executable(Memengine ${SOURCES})
target_compile_features(Memengine PRIVATE cxx_std_17)
target_link_libraries(Memengine PRIVATE SFML::Graphics)
