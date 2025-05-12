cmake_minimum_required(VERSION 3.10)
project(Rebounz)

if (WIN32)
    set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
    set(CMAKE_PREFIX_PATH "C:/path/to/SFML")
    message(STATUS "Compiling for Windows")
elseif (UNIX)
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")
endif()

find_program(CLANG_FORMAT_EXE NAMES clang-format)

if (CLANG_FORMAT_EXE)
    # Liste des fichiers à formater (ajuste selon ton projet)
    file(GLOB_RECURSE ALL_SOURCE_FILES 
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/include/*.hpp"
    )

    add_custom_target(
        format
        COMMAND ${CLANG_FORMAT_EXE}
        -i
        -style=file
        ${ALL_SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running clang-format on source files"
    )
else()
    message(WARNING "clang-format not found!")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")
find_package(SFML 2.5 REQUIRED graphics window system)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

