cmake_minimum_required(VERSION 3.13)
project(kconv VERSION 0.0.1 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(kconv "")
target_compile_options(kconv PRIVATE -Wall -Wextra -Wpedantic -Werror)
add_subdirectory(src)
