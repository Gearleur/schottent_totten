cmake_minimum_required(VERSION 3.24)
project(schottent_totten)

set(CMAKE_CXX_STANDARD 17)

add_executable(schottent_totten main.cpp Game/Game.cpp Game/Game.h Utils/enums.cpp Utils/enums.h Card/Card.cpp Card/Card.h Player/Player.cpp Player/Player.h Board/Board.cpp Board/Board.h Border/Boarder.cpp Border/Boarder.h Player/Human/Human.cpp Player/Human/Human.h Card/Clan/Clan.cpp Card/Clan/Clan.h "Board/Classique Deck/Deck.cpp" "Board/Classique Deck/Deck.h")
