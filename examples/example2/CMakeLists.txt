cmake_minimum_required(VERSION 3.10)

project(example2)

find_package(doctest CONFIG REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(prime_test01 prime_test01.cpp)
add_executable(drawings1 qt_drawings1.cpp)

target_link_libraries(prime_test01 PRIVATE doctest::doctest-header-only)
target_link_libraries(drawings1 PRIVATE Qt6::Widgets)

set(TARGETS prime_test01)

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
