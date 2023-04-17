cmake_minimum_required (VERSION 3.8)

add_executable (cmake_2 "main.cpp" "header.h" "func.cpp" "generator.cpp" "MyLib.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cmake_2 PROPERTY CXX_STANDARD 20)
endif()


