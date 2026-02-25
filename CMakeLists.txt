cmake_minimum_required(VERSION 3.16)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

find_package(Drogon REQUIRED)

add_executable(TaskManager
    src/main.cc
    src/controllers/TaskController.cpp
)

target_link_libraries(TaskManager PRIVATE Drogon::Drogon)