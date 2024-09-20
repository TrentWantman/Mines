cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Mines)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Mines main.cpp texture.cpp texture.h tile.h random.cpp random.h WagerOptions.h CashoutButton.h mine_options.h multiplier.h
        multiplier.h
        main.cpp
        main.cpp
        main.cpp
        main.cpp
        GameController.cpp
        GameController.h
        CashoutButton.cpp
        Tile.cpp
        WagerOptions.cpp
        MineOptions.cpp
        MineOptions.h
        UI.cpp
        UI.h
        GameState.h
        BetButton.cpp
        BetButton.h
        EasterEgg.cpp
        EasterEgg.h
        Wallpapers.cpp
        Wallpapers.h
        WallPaper.cpp
        WallPaper.h
        Bank.cpp
        Bank.h)
target_link_libraries(Mines sfml-graphics sfml-audio)