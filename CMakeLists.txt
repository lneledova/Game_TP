cmake_minimum_required(VERSION 3.10)


project(Game)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Code)

add_executable(Game Code/main.cpp Code/lib.cpp Code/Player.cpp Code/Builder.cpp Code/Director.cpp Code/Application.cpp Code/Decorator.cpp)
target_include_directories(Game PUBLIC ${CMAKE_CURRENT_LIST_DIR})


project(GameTest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
add_executable(GameTest test.cpp)

target_link_libraries(GameTest ${GTEST_LIBRARIES} pthread)





