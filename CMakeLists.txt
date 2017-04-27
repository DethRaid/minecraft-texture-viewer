cmake_minimum_required(VERSION 3.6)
project(TexturePreviewer)

#include(${CMAKE_CURRENT_LIST_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()

include_directories(E:\\wxWidgets-3.1.0\\include E:\\wxWidgets-3.1.0\\include\\msvc)
link_directories(E:\\wxWidgets-3.1.0\\lib\\vc_lib)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-D_UNICODE -D_CRT_SECURE_NO_WARNINGS)

set(SOURCE_FILES src/view/main_window.cpp src/view/main_window.h src/view/noname.cpp src/view/app.cpp)
add_executable(TexturePreviewer ${SOURCE_FILES})

target_link_libraries(TexturePreviewer wxbase31ud wxmsw31ud_core wxmsw31ud_gl)