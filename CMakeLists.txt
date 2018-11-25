cmake_minimum_required(VERSION 3.5)
project(hello)
set(SRCFILE ${CMAKE_CURRENT_SOURCE_DIR}/src/hello.cxx)
add_library(hello SHARED ${SRCFILE})
target_include_directories(hello PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>)
target_compile_options(hello PRIVATE -Wall -O3)

install(TARGETS hello 
    EXPORT hello-target
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)

install(EXPORT hello-target
    FILE
        HelloTargets.cmake
    NAMESPACE
        hello::
    DESTINATION
        ${CMAKE_INSTALL_PREFIX}/cmake/hello
)

install (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/hello 
         DESTINATION ${CMAKE_INSTALL_PREFIX}/include/
         FILES_MATCHING PATTERN "*.h")


export(EXPORT hello-target FILE ${CMAKE_CURRENT_BINARY_DIR}/cmake/hello/HelloTargets.cmake NAMESPACE  hello::)
#export(PACKAGE hello)
include("${CMAKE_CURRENT_BINARY_DIR}/cmake/hello/HelloTargets.cmake")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
