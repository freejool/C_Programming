cmake_minimum_required(VERSION 3.19)
project(10_ C)

set(CMAKE_C_STANDARD 99)

include_directories("/opt/homebrew/Cellar/mysql/8.0.25_1/include")
include_directories("/opt/homebrew/Cellar/mysql/8.0.25_1/lib")

add_executable(10_ main.c head.h sql.h)

target_link_libraries(10_ /opt/homebrew/Cellar/mysql/8.0.25_1/lib/libmysqlclient.21.dylib)
