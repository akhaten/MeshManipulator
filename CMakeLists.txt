cmake_minimum_required(VERSION 3.20)

project(learnopengl)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glm)
add_subdirectory(libs/eigen)
add_subdirectory(libs/OpenMesh)

#include_directories(libs/glfw/include)
#include_directories(libs/glm)
#include_directories(libs/eigen/Eigen)




find_package(OpenGL)
find_package(GLEW REQUIRED)


set(MESH
        src/Mesh/Mesh.hpp
        src/Mesh/Mesh.cpp
        src/Mesh/SurfaceMesh.hpp
        src/Mesh/SurfaceMesh.cpp
        src/Mesh/CurveMesh.hpp
        src/Mesh/CurveMesh.cpp
        src/Mesh/Mesh2.hpp
        src/Mesh/Mesh2.cpp
        src/Mesh/SurfaceMesh2.hpp
        src/Mesh/SurfaceMesh2.cpp
        
        )

set(UTILS
        src/Utils/Shader.hpp
        src/Utils/Shader.cpp
        src/Utils/Scene.hpp
        src/Utils/Scene.cpp
        src/Utils/Drawable.hpp
        src/Utils/Drawable.cpp
        )

set(GEOMETRY
        src/Geometry/Curve/BernsteinPolynom.hpp
        src/Geometry/Curve/BernsteinPolynom.cpp
        src/Geometry/Curve/BezierCurve.hpp
        src/Geometry/Curve/BezierCurve.cpp
        src/Geometry/Surface/BezierSurface.hpp
        src/Geometry/Surface/BezierSurface.cpp
        )

set(APPLICATION
        src/Window/Application.hpp
        src/Window/Application.cpp
        )

set(SRC
        ${MESH}
        ${UTILS}
        ${GEOMETRY}
        ${APPLICATION}
        #${OPENMESH_LIBRARIES}
        # ${open_mesh_sources}
        # ${om_headers}
        # ${om_sources}
        )

set(GLM_INCLUDE_DIR libs/glm)

include_directories(
        ${GLM_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
        ${OPENMESH_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIR}
        ${EIGEN_INCLUDE_DIR}
        src/Mesh
        src/Geometry
        src/Utils
        src/Window
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



add_executable(${PROJECT_NAME} src/main.cpp ${SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE ${EXTERNAL_LIB})
