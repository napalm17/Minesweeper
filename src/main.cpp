#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include "field.h"
#include "gameplay.h"
#include <map>
#include <array>

void wait(int t) {
    std::this_thread::sleep_for(std::chrono::milliseconds(t));
}

void ClearScreen() {
    for (int i = 0; i < 100; ++i) {
        std::cout << std::endl;
    }
}

void PrintBanner() {
    std::string banner;
    banner = R"( 
                                                    ___  ___                                                   
                                                    |  \/  (_)                                                  
                                                    | .  . |_ _ __   ___  _____      _____  ___ _ __   ___ _ __ 
                                                    | |\/| | | '_ \ / _ \/ __\ \ /\ / / _ \/ _ \ '_ \ / _ \ '__|
                                                    | |  | | | | | |  __/\__ \\ V  V /  __/  __/ |_) |  __/ |   
                                                    \_|  |_/_|_| |_|\___||___/ \_/\_/ \___|\___| .__/ \___|_|   
                                                                                            | |              
                                                                                            |_|              
        )";
    std::cout << banner << std::endl;
}

// Function to get the configuration based on difficulty
std::array<int, 3> getDifficultyConfig(const std::string& difficulty) {
    std::map<std::string, std::array<int, 3>> difficultyMap = {
        {"beginner", {8, 8, 10}},   // rows, cols, numMines
        {"advanced", {16, 16, 20}},
        {"pro", {32, 32, 80}}
    };

    if (difficultyMap.find(difficulty) != difficultyMap.end()) {
        return difficultyMap[difficulty]; 
    } else {
        return {-1, -1, -1}; // Invalid input
    }
}

std::array<int, 3> SelectDifficulty() {
    std::string difficulty;
    std:: cout << "Please select difficulty(beginner/advanced/pro):";
    std::cin >> difficulty;
    std::array<int, 3> config = getDifficultyConfig(difficulty);

    // Check if the input was valid
    if (config[0] != -1) {
        std::cout << "Spielfeld von " << config[0] << " mal " << config[1]
                  << " (" << config[0] * config[1] << ") Feldern mit "
                  << config[2] << " Minen (Minendichte "
                  << static_cast<float>(config[2]) / (config[0] * config[1]) * 100
                  << "%)." << std::endl;
    } else {
        std::cout << "Falsche Angabe!" << std::endl;
    }
    return config;
}


int main (int argc, char* argv[]) {
    PrintBanner();
    auto [rows, cols, numMines] = SelectDifficulty();
    wait(1000);
    ClearScreen();
    PrintBanner();

    Field field(rows, cols);

    GamePlay gameplay(field);
    gameplay.placeMines(numMines);
    gameplay.runGame2();

}