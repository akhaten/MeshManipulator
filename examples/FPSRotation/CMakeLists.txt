cmake_minimum_required(VERSION 3.20)

project(FPSRotation)

set(SRC
    MyViewer.hpp
    MyViewer.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE MeshManipulator)