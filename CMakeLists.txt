cmake_minimum_required(VERSION 3.3)
project(qtsize)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(qtsize ${CMAKE_CURRENT_SOURCE_DIR}/src/MainWindow.cxx
                      ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cxx)

target_link_libraries(qtsize PUBLIC Qt6::Widgets)

install(TARGETS qtsize DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
