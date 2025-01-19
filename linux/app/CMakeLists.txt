cmake_minimum_required(VERSION 3.30.6)

project(app LANGUAGES CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(app)
target_include_directories(app PRIVATE ../curves/include)
target_sources(app PRIVATE src/main.cc)

# CMAKE_PREFIX_PATH=path/to/package
find_package(TBB 2022.0.0 REQUIRED)

set(CMAKE_MODULE_PATH "cmake")

find_package(CUR REQUIRED)

target_link_directories(app PRIVATE ../curves/build)
target_link_libraries(app PRIVATE TBB::tbb PRIVATE curves)