cmake_minimum_required(VERSION 3.26)
project(Tietokonejarjestelmat C)

set(CMAKE_C_STANDARD 23)

add_executable(Tietokonejarjestelmat main.c
        viikko6.c
        viikko7.c
        viikko9.c
        viikko10.c)
target_link_libraries(Tietokonejarjestelmat m)
