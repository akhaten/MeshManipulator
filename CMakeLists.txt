cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_BUILD_TYPE "Debug")

# set(CMAKE_C_COMPILER "/nix/store/a64w6zy8w9hcj6b4g5nz0dl6zyd24c1x-gcc-wrapper-11.3.0/bin/gcc")
# set(CMAKE_CXX_COMPILER "/nix/store/a64w6zy8w9hcj6b4g5nz0dl6zyd24c1x-gcc-wrapper-11.3.0/bin/g++")
# set(CMAKE_C_COMPILER_WORKS 1)
# set(CMAKE_CXX_COMPILER_WORKS 1)

project(MeshManipulator)



set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(docs)

find_package(OpenGL)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Eigen3 REQUIRED)
#find_package(Assimp)
find_package(OpenMesh)


set(PATH_SRC ${CMAKE_SOURCE_DIR}/src)
set(PATH_MESH_MANIPULATOR ${PATH_SRC}/MeshManipulator)

set(PATH_MESH ${PATH_MESH_MANIPULATOR}/Mesh)
set(PATH_GEOMETRY ${PATH_MESH_MANIPULATOR}/Geometry)
set(PATH_UTILS ${PATH_MESH_MANIPULATOR}/Utils)
set(PATH_WINDOW ${PATH_MESH_MANIPULATOR}/Window)

# set(PATH_LIBS ${CMAKE_SOURCE_DIR}/libs)




# add_definitions(-DOM_STATIC_BUILD)
# add_link_options(-lOpenMesh)


set(MESH
	${PATH_MESH}/OpenGLObject.hpp
	${PATH_MESH}/OpenGLObject.cpp
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
	${PATH_UTILS}/Camera.hpp
	${PATH_UTILS}/Camera.cpp
	${PATH_UTILS}/Renderer.hpp
	${PATH_UTILS}/Renderer.cpp
	${PATH_UTILS}/Lights/Light.hpp
	${PATH_UTILS}/Lights/Light.cpp
	${PATH_UTILS}/Lights/DirectionalLight.hpp
	${PATH_UTILS}/Lights/DirectionalLight.cpp
	${PATH_UTILS}/Lights/SpotLight.hpp
	${PATH_UTILS}/Lights/SpotLight.cpp
)



set(GEOMETRY
	${PATH_GEOMETRY}/Curve/BernsteinPolynom.hpp
	${PATH_GEOMETRY}/Curve/BernsteinPolynom.cpp
	${PATH_GEOMETRY}/Curve/BezierCurve.hpp
	${PATH_GEOMETRY}/Curve/BezierCurve.cpp
	${PATH_GEOMETRY}/Surface/BezierSurface.hpp
	${PATH_GEOMETRY}/Surface/BezierSurface.cpp
)

set(WINDOW
	${PATH_WINDOW}/Application.hpp
	${PATH_WINDOW}/Application.cpp
	${PATH_WINDOW}/Viewer.hpp
	${PATH_WINDOW}/Viewer.cpp
)

set(SRC
	${MESH}
	${UTILS}
	${GEOMETRY}
	${WINDOW}
)

# set(GLM_INCLUDE_DIR libs/glm)

include_directories(

	${PATH_MESH} 
	${PATH_GEOMETRY}
	${PATH_UTILS}
	${PATH_WINDOW}

	#${GLM_INCLUDE_DIR}
	#${GLEW_INCLUDE_DIR}
	#${OPENMESH_INCLUDE_DIRS}
	#${OPENMESH_LIBRARY_DIR}
	#${GLFW_INCLUDE_DIR}
	#${EIGEN_INCLUDE_DIR}

)

set(EXTERNAL_LIB
	# ${OPENMESH_LIBRARIES}
	# ${GLFW_LIBRARIES}
	${GLEW_LIBRARY}
	${OPENGL_LIBRARY}
	glfw
	# OpenGL
	GLEW
	OpenMeshCore
	#glm
)


add_library(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PATH_SRC})
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTERNAL_LIB})

add_subdirectory(examples)



# https://www.youtube.com/watch?v=I5d45OOAXPk&t=52s
# include(FetchContent)

# FetchContent_Declare(
#         OpenMesh
#         GIT_REPOSITORY https://gitlab.vci.rwth-aachen.de:9000/OpenMesh/OpenMesh
#         GIT_TAG OpenMesh-9.0
# )

# ----------------------------------------

# https://cmake.org/cmake/help/latest/manual/cmake.1.html
## PIPELINE CLASSIQUE
# mkdir /path/to/my/build/folder
# cd /path/to/my/build/folder
# cmake ..
# make

## PIPELINE PLUS INTELLIGENTE/FLEXIBLE
# mkdir /path/to/my/build/folder
# cmake /path/to/my/source/folder/with/CMakeLists.txt -B /path/to/my/build/folder
# cmake --build /path/to/my/build/folder

# ----------------------------------------

## POUR AJOUTER UNE COMMANDE PERSONNALISER À MAKE
# add_custom_target(run
#     COMMAND binary
#     DEPENDS binary
#     WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
# )

# cmake -DCMAKE_PREFIX_INSTALL


# PIPELINE

# mkdir libs-external
# mkdir libs-external/build
# mkdir MeshManipulator/libs
# cmake -S libs-external -B libs-external/build -DCMAKE_PREFIX_INSTALL=MeshManipulator/libs -DBUILD_EXTERNAL_LIBS=ON
# cmake --build libs-external

# mkdir MeshManipulator/build
# 


