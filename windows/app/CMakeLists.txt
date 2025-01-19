cmake_minimum_required(VERSION 3.30.6)

project(app LANGUAGES CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(app)
target_include_directories(app PRIVATE ../curves/include PRIVATE ../oneTBB-tbb_2020/include)
target_sources(app PRIVATE src/main.cpp)

set(CMAKE_MODULE_PATH "cmake")

find_package(TBB 2020 REQUIRED)
find_package(CUR REQUIRED)

target_link_directories(app PRIVATE ../curves/build PRIVATE ../oneTBB-tbb_2020/build/windows_intel64_gcc_mingw14.1.0_release)
target_link_libraries(app PRIVATE tbb PRIVATE curves)
