cmake_minimum_required(VERSION 3.0.0)

project(laba1)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    abstractanimal.h
    cat.h cat.cpp
    dog.h dog.cpp
    commandhandler.h commandhandler.cpp
    patientdata.h patientdata.cpp
    myalgorithm.h
)
find_package(Qt5Core CONFIG REQUIRED)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Core)
