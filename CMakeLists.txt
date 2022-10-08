cmake_minimum_required(VERSION 3.20)

project(MeshManipulator)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glm)
add_subdirectory(libs/eigen)
add_subdirectory(libs/OpenMesh)

#include_directories(libs/glfw/include)
#include_directories(libs/glm)
#include_directories(libs/eigen/Eigen)


set(PATH_SRC ${CMAKE_SOURCE_DIR}/src)
set(PATH_MESH_MANIPULATOR ${PATH_SRC}/MeshManipulator)

set(PATH_MESH ${PATH_MESH_MANIPULATOR}/Mesh)
set(PATH_GEOMETRY ${PATH_MESH_MANIPULATOR}/Geometry)
set(PATH_UTILS ${PATH_MESH_MANIPULATOR}/Utils)
set(PATH_WINDOW ${PATH_MESH_MANIPULATOR}/Window)

# set(PATH_LIBS ${CMAKE_SOURCE_DIR}/libs)

find_package(OpenGL)
find_package(GLEW REQUIRED)


set(MESH
        ${PATH_MESH}/Mesh.hpp
        ${PATH_MESH}/Mesh.cpp
        ${PATH_MESH}/ObjectMesh.hpp
        ${PATH_MESH}/ObjectMesh.cpp
        ${PATH_MESH}/CurveMesh.hpp
        ${PATH_MESH}/CurveMesh.cpp
)

set(UTILS
        ${PATH_UTILS}/Shader.hpp
        ${PATH_UTILS}/Shader.cpp
        ${PATH_UTILS}/Scene.hpp
        ${PATH_UTILS}/Scene.cpp
        ${PATH_UTILS}/Drawable.hpp
        ${PATH_UTILS}/Drawable.cpp
        )

set(GEOMETRY
        ${PATH_GEOMETRY}/Curve/BernsteinPolynom.hpp
        ${PATH_GEOMETRY}/Curve/BernsteinPolynom.cpp
        ${PATH_GEOMETRY}/Curve/BezierCurve.hpp
        ${PATH_GEOMETRY}/Curve/BezierCurve.cpp
        ${PATH_GEOMETRY}/Surface/BezierSurface.hpp
        ${PATH_GEOMETRY}/Surface/BezierSurface.cpp
        )

set(APPLICATION
        ${PATH_WINDOW}/Application.hpp
        ${PATH_WINDOW}/Application.cpp
        )

set(SRC
        ${MESH}
        ${UTILS}
        ${GEOMETRY}
        ${APPLICATION}
)

set(GLM_INCLUDE_DIR libs/glm)

include_directories(

        ${GLM_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
        ${OPENMESH_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIR}
        ${EIGEN_INCLUDE_DIR}

        ${PATH_MESH} 
        ${PATH_GEOMETRY}
        ${PATH_UTILS}
        ${PATH_WINDOW}

)

set(EXTERNAL_LIB
        ${OPENMESH_LIBRARY}
        # ${GLFW_LIBRARY}
        ${GLEW_LIBRARY}
        ${OPENGL_LIBRARY}
        glfw
        OpenGL
        GLEW
)


add_library(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PATH_SRC})
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTERNAL_LIB})

message(${CMAKE_PROJECT_NAME})

add_subdirectory(examples)

# add_executable(${PROJECT_NAME} src/main.cpp ${SRC})
# target_link_libraries(${PROJECT_NAME} PRIVATE ${EXTERNAL_LIB})
