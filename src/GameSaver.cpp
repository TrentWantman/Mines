#include "GameSaver.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#ifdef _WIN32
    #include <windows.h>

#else
    #include <unistd.h>
#endif

GameSaver::GameSaver() {}

// Helper function to get cross-platform hidden directory
std::string GameSaver::getSaveFilePath() {
    std::string hiddenDir;

#ifdef _WIN32
    // Use getenv to get the APPDATA path
    const char* appDataPath = std::getenv("APPDATA");  // Get APPDATA path
    if (appDataPath != nullptr) {
        hiddenDir = std::string(appDataPath) + "\\MyGame";  // Append your folder
    } else {
        hiddenDir = "C:\\MyGame";  // Fallback path if APPDATA is not set
    }

    // Create directory if it doesn't exist
    CreateDirectory(hiddenDir.c_str(), NULL);

#elif __APPLE__
    // Use getenv to get the HOME path on macOS
    const char* homePath = std::getenv("HOME");
    if (homePath != nullptr) {
        hiddenDir = std::string(homePath) + "/Library/Application Support/MyGame";
    } else {
        hiddenDir = "/tmp/MyGame";  // Fallback path if HOME is not set
    }

#elif __linux__
    // Use getenv to get the HOME path on Linux
    const char* homePath = std::getenv("HOME");
    if (homePath != nullptr) {
        hiddenDir = std::string(homePath) + "/.config/MyGame";
    } else {
        hiddenDir = "/tmp/MyGame";  // Fallback path if HOME is not set
    }

#endif


    std::filesystem::create_directories(hiddenDir); // Ensure the hidden directory exists
    return hiddenDir + "/savefile.dat";  // Use binary file format
}

void GameSaver::saveGame(EasterEgg* easterEgg, Menu* menu, Bank* bank, GameState* gameState, History* history, PayoutDisplay* payoutDisplay, Wallpapers* wallpapers, double wagerAmount, Jeff* jeff) {
    std::ofstream mainSave(getSaveFilePath(), std::ios::binary);

    if (!mainSave) {
        std::cerr << "Failed to open file for saving." << std::endl;
        return;
    }

    // Save game state
    double balanceToSave = (*gameState == GameState::Playing) ? (bank->balance + wagerAmount) : bank->balance;
    mainSave.write(reinterpret_cast<const char*>(&balanceToSave), sizeof(balanceToSave));

    mainSave.write(reinterpret_cast<const char*>(&easterEgg->step), sizeof(easterEgg->step));
    mainSave.write(reinterpret_cast<const char*>(&jeff->owedMoney), sizeof(jeff->owedMoney));

    // Save wallpapers unlocked status
    for (const auto& wallpaper : wallpapers->wallPaperMenu) {
        mainSave.write(reinterpret_cast<const char*>(&wallpaper.unlocked), sizeof(wallpaper.unlocked));
    }

    // Save history of rounds
    size_t roundsSize = history->rounds.size();
    mainSave.write(reinterpret_cast<const char*>(&roundsSize), sizeof(roundsSize));
    for (const auto& round : history->rounds) {
        mainSave.write(reinterpret_cast<const char*>(&round.mines), sizeof(round.mines));
        mainSave.write(reinterpret_cast<const char*>(&round.gemsRevealed), sizeof(round.gemsRevealed));
        mainSave.write(reinterpret_cast<const char*>(&round.wager), sizeof(round.wager));
        mainSave.write(reinterpret_cast<const char*>(&round.multiplier), sizeof(round.multiplier));
        mainSave.write(reinterpret_cast<const char*>(&round.payout), sizeof(round.payout));
    }

    mainSave.close();
}

void GameSaver::loadGame(EasterEgg* easterEgg, Menu* menu, Bank* bank, GameState* gameState, History* history, PayoutDisplay* payoutDisplay, Wallpapers* wallpapers, double wagerAmount, Jeff* jeff) {
    std::ifstream mainLoad(getSaveFilePath(), std::ios::binary);

    if (!mainLoad) {
        std::cerr << "Failed to open file for loading." << std::endl;
        return;
    }

    if (mainLoad.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Save file is empty. No data to load." << std::endl;
        mainLoad.close();
        return;
    }

    // Load bank balance
    double balance;
    mainLoad.read(reinterpret_cast<char*>(&balance), sizeof(balance));
    bank->withdrawl(bank->balance);
    bank->deposit(balance);

    // Load EasterEgg step
    mainLoad.read(reinterpret_cast<char*>(&easterEgg->step), sizeof(easterEgg->step));

    // Load Jeff's owed money
    mainLoad.read(reinterpret_cast<char*>(&jeff->owedMoney), sizeof(jeff->owedMoney));

    // Load wallpapers unlocked status
    int index = 1;
    for (auto& wallpaper : wallpapers->wallPaperMenu) {
        bool unlocked;
        mainLoad.read(reinterpret_cast<char*>(&unlocked), sizeof(unlocked));
        if (unlocked) {
            wallpapers->unlockWallPaper(index);  // Use index to unlock wallpaper
        }
        index++;
    }

    // Load history of rounds
    size_t roundsSize;
    mainLoad.read(reinterpret_cast<char*>(&roundsSize), sizeof(roundsSize));
    history->rounds.clear(); // Clear existing rounds before loading

    for (size_t i = 0; i < roundsSize; ++i) {
        Round round;
        mainLoad.read(reinterpret_cast<char*>(&round.mines), sizeof(round.mines));
        mainLoad.read(reinterpret_cast<char*>(&round.gemsRevealed), sizeof(round.gemsRevealed));
        mainLoad.read(reinterpret_cast<char*>(&round.wager), sizeof(round.wager));
        mainLoad.read(reinterpret_cast<char*>(&round.multiplier), sizeof(round.multiplier));
        mainLoad.read(reinterpret_cast<char*>(&round.payout), sizeof(round.payout));
        history->rounds.push_back(round);
    }

    mainLoad.close();
}
