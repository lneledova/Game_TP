cmake_minimum_required(VERSION 3.10)


project(Game)


set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Code)

add_subdirectory(googletest-master)

add_executable(Game Code/main.cpp Code/lib.cpp Code/Player.h Code/Player.cpp Code/Builder.h Code/Builder.cpp Code/Director.cpp Code/Director.h Code/Application.cpp Code/Application.h)
target_include_directories(Game PUBLIC ${CMAKE_CURRENT_LIST_DIR})


project(GameTest)


add_executable(GameTest test.cpp test_main.cpp)
target_link_libraries(GameTest gtest gtest_main)
target_include_directories(GameTest PUBLIC ${gtest_SOURCE_DIR}/include ${CMAKE_CURRENT_LIST_DIR})




