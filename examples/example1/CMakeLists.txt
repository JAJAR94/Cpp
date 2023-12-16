cmake_minimum_required(VERSION 3.10)

project(example1)

find_package(fmt CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)

add_executable(main01 main01.cpp)
add_executable(main02 main02.cpp)

add_executable(test01 test01.cpp)
add_executable(test02 test02.cpp)
add_executable(test03 test03.cpp)

target_link_libraries(main02 PRIVATE fmt::fmt-header-only)

target_link_libraries(test01 PRIVATE doctest::doctest-header-only)
target_link_libraries(test02 PRIVATE doctest::doctest-header-only)
target_link_libraries(test03 PRIVATE doctest::doctest-header-only)

set(TARGETS main01 main02 test01 test02 test03)

set_target_properties(
    ${TARGETS}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

foreach(T IN LISTS TARGETS)
    if (MSVC)
        target_compile_options(${T} PRIVATE /Wall /WX)
    else()
        target_compile_options(${T} PRIVATE -Wall -Wextra)
    endif()
endforeach()
