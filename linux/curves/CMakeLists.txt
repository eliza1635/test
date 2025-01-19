cmake_minimum_required(VERSION 3.30.6)

project(curves LANGUAGES CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(include)
add_library(curves SHARED src/curves.cc)
