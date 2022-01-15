cmake_minimum_required(VERSION 3.0.0)
project(ray-tracer VERSION 0.1.0)

add_compile_options(-Wall -Wextra -pedantic -Werror -Werror=vla)

add_executable(ray-tracer "")

add_subdirectory(src)
