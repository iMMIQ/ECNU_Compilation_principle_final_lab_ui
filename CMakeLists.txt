cmake_minimum_required(VERSION 3.22)
project(ECNU_Compilation_principle_final_lab_ui)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(lab main.cpp default_window.h default_window.cpp)

target_link_libraries(lab ${GTKMM_LIBRARIES})
