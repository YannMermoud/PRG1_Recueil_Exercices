cmake_minimum_required(VERSION 3.12)

project(EXERCICES_1)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 20)

# Use Undefined Behavior Sanitizer
add_compile_options(-Wall -Wextra -Wpedantic -g)

file(GLOB helloworld_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")

add_executable(Exercice9 ${helloworld_SRC})