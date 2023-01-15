cmake_minimum_required(VERSION 3.16)

find_package(Qt6 6.2 COMPONENTS Core REQUIRED)

set(SOURCES
    persback.cpp
    persdata.cpp
    persmodel.cpp
    saveloadconf.cpp
)

set(HEADERS
    persback.h
    persdata.h
    persmodel.h
    saveloadconf.h
)

qt_add_library(srcLibs
    STATIC
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(srcLibs
        Qt6::Core
)
