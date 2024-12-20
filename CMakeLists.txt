cmake_minimum_required(VERSION 3.28)
project(cpp_meta_box)

set(CMAKE_CXX_STANDARD 23)

add_executable(meta_prime meta_prime.cpp)
add_executable(meta_sqrt meta_sqrt.cpp)
add_executable(meta_isprime meta_isprime.cpp)
add_executable(array_dot_product array_dot_product.cpp)
add_executable(const_expr_box ConstExprBoxMain.cpp ConstExprBox.cpp)
