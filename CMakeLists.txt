cmake_minimum_required(VERSION 3.16)

project(RandTourPers VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick Sql REQUIRED)

add_subdirectory(src)
include_directories(src)

qt_add_executable(${PROJECT_NAME}
    main.cpp
)

qt_add_qml_module(${PROJECT_NAME}
    URI res
    VERSION 1.0
    QML_FILES qml/main.qml
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME}
    PRIVATE srcLibs Qt6::Quick Qt6::Sql)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/configs/config.json ${CMAKE_CURRENT_BINARY_DIR}/config.json COPYONLY)
