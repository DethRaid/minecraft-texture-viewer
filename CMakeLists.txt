cmake_minimum_required(VERSION 3.6)
project(TexturePreviewer)

include(${CMAKE_CURRENT_LIST_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(E:\\wxWidgets-3.1.0\\include E:\\wxWidgets-3.1.0\\include\\msvc)
link_directories(E:\\wxWidgets-3.1.0\\lib\\vc_lib)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-D_UNICODE -D_CRT_SECURE_NO_WARNINGS)

file(GLOB VIEW_FILES src/view/*.cpp)
file(GLOB RENDER_FILES src/render/*.cpp)

set(SOURCE_FILES ${VIEW_FILES} ${RENDER_FILES} src/render/glad.c)
add_executable(TexturePreviewer ${SOURCE_FILES})

target_link_libraries(TexturePreviewer wxbase31ud wxmsw31ud_core wxmsw31ud_gl)
