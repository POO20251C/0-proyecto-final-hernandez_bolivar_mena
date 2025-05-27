cmake_minimum_required(VERSION 3.30)

project(under_dark_dungeons)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(under_dark_dungeons
        src/Arma.cpp
        src/Arma.h
        src/Armadura.cpp
        src/Armadura.h
        src/Booster_armaduras.cpp
        src/Booster_armaduras.h
        src/Booster_armas.cpp
        src/Booster_armas.h
        src/Efecto.cpp
        src/Efecto.h
        src/Entidad.cpp
        src/Entidad.h
        src/Grupo_jugador.cpp
        src/Grupo_jugador.h
        src/Habilidad.cpp
        src/Habilidad.h
        src/Heroe.cpp
        src/Heroe.h
        src/Objeto.cpp
        src/Objeto.h
        src/Tienda.cpp
        src/Tienda.h
        main.cpp)