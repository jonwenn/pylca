cmake_minimum_required(VERSION 3.16.5)
project(pylca)

set(PYTHON_DIR C:/dev/resources/Python/)

set(Boost_ROOT C:/boost_1_72_0)
set(Boost_INCLUDE_DIR ${Boost_ROOT})
set(Boost_LIBRARY_DIR ${Boost_ROOT}/stage/x64)

set(Boost_DEBUG 1)
find_package(Boost 1.72.0 COMPONENTS python38 REQUIRED)

set(PYTHON_LIBRARY C:/dev/resources/Python/libs)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR} ${PYTHON_LIBRARY})

find_package(PythonLibs 3.8 REQUIRED)
set(PYTHON_LIBRARY ${PYTHON_DIR}/Libs)

set(ARMADILLO_LIBRARY C:/dev/resources/c++/armadillo/examples/lib_win64/libopenblas.lib)
set(ARMADILLO_INCLUDE_DIR C:/dev/resources/c++/armadillo/include/)
find_package(Armadillo REQUIRED)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(LIFE_CYCLE_ASSESSMENT C:/dev/working/lca/cmake-build-release/lca.lib)
elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(LIFE_CYCLE_ASSESSMENT C:/dev/working/lca/cmake-build-debug/lca.lib)
endif()

include_directories(include)
include_directories(${PYTHON_DIR}/include)
include_directories(C:/dev/working/lca/include)
include_directories(${ARMADILLO_INCLUDE_DIRS})
link_directories(${PYTHON_DIR}/Libs)

set(SOURCES source/library.cpp source/library_helper.cpp include/globals.h)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${PYTHON_LIBRARY} ${LIFE_CYCLE_ASSESSMENT} ${ARMADILLO_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".pyd")

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy
            "$<TARGET_FILE:${PROJECT_NAME}>"
            "${PYTHON_DIR}/DLLs/$<TARGET_FILE_NAME:${PROJECT_NAME}>")
endif()