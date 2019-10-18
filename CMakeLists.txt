cmake_minimum_required(VERSION 3.14)
project(entt_meta_boost_dll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})

find_package(entt REQUIRED)
find_package(boost REQUIRED COMPONENTS dll)

add_executable(entt_meta_boost_dll application.cpp)

target_link_libraries(
    entt_meta_boost_dll
    PRIVATE
    boost::boost
    entt::entt
)

if (UNIX)
    TARGET_LINK_LIBRARIES(entt_meta_boost_dll PRIVATE dl)
endif ()

add_library(
    shared_lib
    SHARED
    shared_lib.cpp
)

target_link_libraries(
    shared_lib
    boost::boost
    entt::entt
)
