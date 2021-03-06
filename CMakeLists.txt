cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/lib/ccache/bin/clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17 -Wall -Wextra --pedantic")

project(02.01)
add_executable(02.01 02.01.cpp)

project(02.02)
add_executable(02.02 02.02.cpp)

project(02.03)
add_executable(02.03 02.03.cpp)

project(02.04)
add_executable(02.04 02.04.cpp)

project(02.05)
add_executable(02.05 02.05.cpp)

project(03.01)
add_executable(03.01 03.01.cpp)

project(03.02)
add_executable(03.02 03.02.cpp)

project(03.03)
add_executable(03.03 03.03.cpp)

project(04.01)
add_executable(04.01 04.01.cpp)

project(04.02)
add_executable(04.02 04.02.cpp)

project(04.03)
add_executable(04.03 04.03.cpp)

project(05.01)
add_executable(05.01 05.01.cpp)

project(05.02)
add_executable(05.02 05.02.cpp)

project(05.03)
add_executable(05.03 05.03.cpp)

project(06.01)
add_executable(06.01 06.01.cpp wortspiegel.cpp)

project(06.02)
add_executable(06.02 06.02.cpp)

project(06.03)
add_executable(06.03 06.03.cpp)
target_link_libraries(06.03 X11 pthread)

project(07)
add_executable(07 07.cpp)

project(08.01)
add_executable(08.01 08.01.cpp person.cpp texte.cpp)

project(08.02)
add_executable(08.02 08.02.cpp)
target_link_libraries(08.02 X11 pthread)

project(09)
add_executable(09 09.cpp)

project(10.01)
add_executable(10.01 10.01.cpp 10/binaerer_suchbaum.cpp)

project(10.02)
add_executable(10.02 10.02.cpp 10.02.dir/suchen.h 10.02.dir/catch.h 10.02.dir/unit_tests.cpp 10.02.dir/suchen.cpp)

project(11.02)
add_executable(11.02 11.02.cpp)
target_link_libraries(11.02 X11 pthread)

project(12.01)
add_executable(12.01 12/12.01_and_02.cpp 12/MyRectangle.cpp)
target_link_libraries(12.01 X11 pthread)

project(12.03)
add_executable(12.03 12/03/main.cpp 12/03/collision_test.cpp 12/03/MyRectangle.cpp)
target_link_libraries(12.03 X11 pthread)

project(13.01)
add_executable(13.01 13/01/main.cpp 13/01/MyRectangle.cpp 13/01/MyFilledRectangle.cpp)
target_link_libraries(13.01 X11 pthread)

project(13.02)
add_executable(13.02 
    13/02/main.cpp 
    13/02/unit_tests_charlistenknoten.cpp 
    13/02/unit_tests_mystring2_1.cpp 
    13/02/unit_tests_mystring2_2.cpp 
    13/02/unit_tests_mystring2_3.cpp 
    13/02/unit_tests_append.cpp 
    13/02/MyString2.cpp 
    13/02/unit_tests_delete_all.cpp
)

# offline

project(o.01.01)
add_executable(o.01.01 offline/01.01.cpp)

project(o.02.01)
add_executable(o.02.01 offline/02.01.cpp)

project(o.02.02)
add_executable(o.02.02 offline/02.02.cpp)

project(o.03.01)
add_executable(o.03.01 offline/03.01.cpp)

project(o.03.02)
add_executable(o.03.02 offline/03.02.cpp)

project(o.04.05)
add_executable(o.04.05 offline/04.05.cpp)

project(o.04.10)
add_executable(o.04.10 offline/04.10.cpp)

project(o.04.12)
add_executable(o.04.12 offline/04.12.cpp)

project(o.05.05)
add_executable(o.05.05 offline/05.05.cpp)

project(o.05.09)
add_executable(o.05.09 offline/05.09.cpp)

project(o.06.01)
add_executable(o.06.01 offline/06.01.cpp)

project(o.06.03)
add_executable(o.06.03 offline/06.03.cpp)

project(o.07.01)
add_executable(o.07.01 offline/07.01.cpp)

project(o.07.05)
add_executable(o.07.05 offline/07.05.cpp)

project(o.08.03)
add_executable(o.08.03 offline/08.03.cpp)

