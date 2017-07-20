cmake_minimum_required(VERSION 3.6)
project(TexturePreviewer)

include(${CMAKE_CURRENT_LIST_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Build where I want you to dammit
set(BUILD_DIR ${CMAKE_CURRENT_LIST_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-D_UNICODE -D_CRT_SECURE_NO_WARNINGS)

file(GLOB VIEW_FILES src/view/*.cpp)
file(GLOB RENDER_FILES src/render/*.cpp)
file(GLOB MOUSE_FILES src/input/*.cpp)

file(GLOB NDF_FILES 3rdparty/nativefiledialog/src/*.c*)

file(GLOB RENDER_HEADERS src/render/*.h)

set(SOURCE_FILES ${VIEW_FILES} ${RENDER_FILES} ${MOUSE_FILES} src/render/glad.c ${NDF_FILES})
add_executable(TexturePreviewer ${SOURCE_FILES})

target_include_directories(TexturePreviewer
        PUBLIC ${CONAN_INCLUDE_DIRS_GLFW}
        PUBLIC 3rdparty/nativefiledialog/src/include)
target_link_libraries(TexturePreviewer ${CONAN_LIBS_GLFW})
