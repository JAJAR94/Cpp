cmake_minimum_required(VERSION 3.0.0)
project(q1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(q1.1 hw2.1.1.cpp)
add_executable(q1.2 hw2.1.2.cpp)
add_executable(q1.3 hw2.1.3.cpp)
add_executable(q2.1 hw2.2.1.cpp header2.cpp)
add_executable(q2.2 hw2.2.2.cpp header2.cpp)
add_executable(q2.3 hw2.2.3.cpp header2.cpp)
add_executable(q3 hw3.1.cpp header3.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
