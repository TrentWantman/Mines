cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Mines)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Mines src/main.cpp src/Texture.cpp src/Texture.h src/Tile.h src/random.cpp src/random.h src/WagerOptions.h src/CashoutButton.h src/mine_options.h src/multiplier.h
        src/multiplier.h
        src/main.cpp
        src/main.cpp
        src/main.cpp
        src/main.cpp
        src/GameController.cpp
        src/GameController.h
        src/CashoutButton.cpp
        src/Tile.cpp
        src/WagerOptions.cpp
        src/MineOptions.cpp
        src/MineOptions.h
        src/UI.cpp
        src/UI.h
        src/GameState.h
        src/BetButton.cpp
        src/BetButton.h
        src/EasterEgg.cpp
        src/EasterEgg.h
        src/Wallpapers.cpp
        src/Wallpapers.h
        src/WallPaper.cpp
        src/WallPaper.h
        src/Bank.cpp
        src/Bank.h
        src/Menu.cpp
        src/Menu.h
        src/PayoutDisplay.cpp
        src/PayoutDisplay.h
        src/History.cpp
        src/History.h
        src/GameSaver.cpp
        src/GameSaver.h
        src/Jeff.cpp
        src/Jeff.h)
target_link_libraries(Mines sfml-graphics sfml-audio)