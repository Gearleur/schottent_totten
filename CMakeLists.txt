cmake_minimum_required(VERSION 3.24)
project(schottent_totten)

set(CMAKE_CXX_STANDARD 17)

add_executable(schottent_totten main.cpp Game/Game.cpp Game/Game.h Card/card.cpp Card/card.h Board/board.cpp Board/board.h Player/player.cpp Player/player.h)
