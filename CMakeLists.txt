cmake_minimum_required(VERSION 3.5...4.0)
project(Recognizer_automata CXX C)
set(SOURCE src/main.cpp)
add_library(linked_list libs/list/list.c)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} linked_list)