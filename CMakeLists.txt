cmake_minimum_required(VERSION 2.8)

project(strategy_game)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML COMPONENTS graphics audio REQUIRED)

include_directories(strategy_game/Textures)

set(SOURCES strategy_game/main.cpp)

set(GAME strategy_game/game.cpp)
set(UNITS strategy_game/units.cpp)
set(ARCHERS strategy_game/archers.cpp)
set(KNIGHTS strategy_game/knights.cpp)
set(PHOENIX strategy_game/phoenix.cpp)
set(BUTTONS strategy_game/Buttons.cpp)
set(FACT strategy_game/factory.cpp)



add_executable(strategy ${SOURCES} ${GAME} ${UNITS} ${ARCHERS} ${KNIGHTS} ${PHOENIX} ${BUTTONS} ${FACT})
target_link_libraries(strategy sfml-graphics sfml-audio)