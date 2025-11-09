cmake_minimum_required(VERSION 3.16)
project(mulsim LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(propagation INTERFACE)
target_include_directories(propagation
   INTERFACE ${PROJECT_SOURCE_DIR}/include
)

include(FetchContent)

FetchContent_Declare(
    eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.1
)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(eigen)
FetchContent_MakeAvailable(argparse)


find_package(OpenMP REQUIRED)

target_link_libraries(propagation INTERFACE Eigen3::Eigen)
target_link_libraries(propagation INTERFACE OpenMP::OpenMP_CXX)

target_compile_options(propagation INTERFACE -Wall -O3)

add_subdirectory(cli)
