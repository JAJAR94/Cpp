cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

# Add the source files
set(SOURCES
    main.cpp
    classes/Teacher.cpp
    classes/Login.cpp
    classes/Homework.cpp
    classes/Register.cpp
    classes/Student.cpp
    classes/User.cpp
    classes/globals.cpp
    
)

# Add the header files
set(HEADERS
    classes/Teacher.hpp
    classes/Login.hpp
    classes/Homework.hpp
    classes/Register.hpp
    classes/Student.hpp
    classes/User.hpp
    classes/globals.hpp
)

add_executable(main ${SOURCES} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
