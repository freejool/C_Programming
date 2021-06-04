cmake_minimum_required(VERSION 3.19)
project(10_ C)
project(test C)

set(CMAKE_C_STANDARD 11)



add_executable(10_ main.c head.h conn.h modules.h)
target_link_libraries(10_ ws2_32)

add_executable(test test.c head.h conn.h modules.h)
target_link_libraries(test ws2_32)

