cmake_minimum_required(VERSION 3.24)
project(schottent_totten)

set(CMAKE_CXX_STANDARD 17)

add_executable(schottent_totten main.cpp Game/Game.cpp Game/Game.h Board/board.cpp Board/board.h Player/player.cpp Player/player.h Border/border.cpp Border/border.h Utils/enums.cpp Utils/enums.h Card/Card.cpp Card/Card.h)
