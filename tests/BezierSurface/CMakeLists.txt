cmake_minimum_required(VERSION 3.20)


include_directories(${SRC})

add_executable(learnopengl main.cpp ../${SRC})
target_link_libraries(learnopengl PRIVATE ${EXTERNAL_LIB})
