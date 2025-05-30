cmake_minimum_required(VERSION 3.10)

project(mi_proyecto VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

add_executable(mi_proyecto
    main.cpp src/Arma.cpp
src/Habilidad.cpp
src/Booster_armas.cpp
src/Objeto.cpp
src/Efecto.cpp
src/Heroe.cpp
src/Entidad.cpp
src/Grupo_jugador.cpp
src/Armadura.cpp
src/Tienda.cpp
src/GrupoEnemigo.cpp
src/Booster_armaduras.cpp
)
