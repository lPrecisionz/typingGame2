cmake_minimum_required(VERSION 3.0.0)
project(typingGame VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(typingGame src/main.cpp src/game.cpp src/text.cpp)
target_include_directories(typingGame PUBLIC headers) #incluindo headers

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)