cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME MIIND)

project(${PROJECT_NAME})

set(SOURCE_FILES
        main.cpp
        glad/src/glad.c
        Mesh/meshBlock.h
        defines.h startUp.cpp startUp.h
        Managers/Window/mainWindow.cpp Managers/Window/mainWindow.h Managers/Mesh/meshManager.h Managers/Mesh/meshManager.cpp
        Utilities/Shaders/shaderUtil.cpp Utilities/Shaders/shaderUtil.h
        Utilities/GlObjs/voaHandler.cpp Utilities/GlObjs/voaHandler.h Utilities/GlObjs/voaModel.cpp Utilities/GlObjs/voaModel.h
        Utilities/GlObjs/vertex.h
        Utilities/Rendering/renderingEngine.h Utilities/Rendering/renderingEngine.cpp
        Camera/basicCamera.h Camera/basicCamera.cpp Utilities/Rendering/meshRenderer.cpp Utilities/Rendering/meshRenderer.h Utilities/Rendering/renderModel.h)

# Libraries
link_directories(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libs/glfw/3.3/lib/) # GLFW


# Excuteable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Include directories
target_include_directories(${PROJECT_NAME}  PUBLIC ${PROJECT_SOURCE_DIR}/libs/glfw/3.3/include/) #GLFW
target_include_directories(${PROJECT_NAME}  PUBLIC ${PROJECT_SOURCE_DIR}/glad/include/) # GLAD
target_include_directories(${PROJECT_NAME}  PUBLIC ${PROJECT_SOURCE_DIR}/includes/) # GLAD

target_link_libraries(${PROJECT_NAME} libglfw.dylib)

# Move project Data to directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Data
        ${PROJECT_BINARY_DIR}/Data
        COMMENT "Copying Data folder to build directory"
        )