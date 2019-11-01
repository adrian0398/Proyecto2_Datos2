cmake_minimum_required(VERSION 3.14)
project(Proyecto2_Datos2)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(Proyecto2_Datos2 main.cpp Estudiantes.cpp Estudiantes.h Cursos.cpp Cursos.h Tablero.cpp Tablero.h Backtracking.cpp Backtracking.h Pathfinding.cpp Pathfinding.h AlgoritmosGeneticos.cpp AlgoritmosGeneticos.h Juego.cpp Juego.h Individual.cpp Individual.h Matriz.cpp Matriz.h List_Posiciones.cpp List_Posiciones.h)


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0 gmodule-2.0 )


include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
include_directories(./include)


add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(Proyecto2_Datos2 ${GTK3_LIBRARIES})