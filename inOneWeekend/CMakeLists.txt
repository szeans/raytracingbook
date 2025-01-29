cmake_minimum_required(VERSION 3.10)  # Minimum CMake version
project(RayTracingInOneWeekend)       # Project name

set(CMAKE_CXX_STANDARD 11)            # Use C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # Require C++11

add_executable(raytracer main.cc)    # Add your source file
