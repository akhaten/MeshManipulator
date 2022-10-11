cmake_minimum_required(VERSION 3.20)

project(tp-info2)

set(SRC
    MyApplication.hpp
    MyApplication.cpp
    MyViewer.hpp
    MyViewer.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE MeshManipulator)