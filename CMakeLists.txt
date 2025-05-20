cmake_minimum_required(VERSION 3.30)
project(Projektas_Dbesijos_paslaugos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projektas_Dbesijos_paslaugos main.cpp
        Spalvos.cpp
        Spalvos.h
        Componentai.cpp
        Componentai.h
        Composite.cpp
        Composite.h
)
