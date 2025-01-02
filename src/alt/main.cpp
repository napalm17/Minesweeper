#include <iostream>
#include <tuple>
#include "Zelle.h"
#include "Spielfeld.h"

void PrintBanner();
std::tuple<int, int, int> SelectDifficulty();
void ClearScreen();
void testZelle(Spielfeld& spielfeld, int x, int y);

int main() {
    PrintBanner();  

    auto [width, height, mines] = SelectDifficulty();
    std::cout << "Selected settings: Width = " << width << ", Height = " << height << ", Mines = " << mines << std::endl;

    Spielfeld spielfeld(width, height, mines);
    
    ClearScreen();  
    
    
    spielfeld.anzeigen();  
    std::cout << "" << std::endl;

    spielfeld.markCell(1, 2);
    std::cout << "" << std::endl;
    spielfeld.anzeigen();
    spielfeld.markCell(1, 2);
    std::cout << "" << std::endl;
    spielfeld.anzeigen();
    spielfeld.uncoverCell(1, 2);
    std::cout << "" << std::endl;
     spielfeld.anzeigen();  
    spielfeld.uncoverCell(3, 2);
    std::cout << "" << std::endl;
     spielfeld.anzeigen();  
    spielfeld.uncoverCell(2, 1);
    std::cout << "" << std::endl;
    spielfeld.uncoverAllCells();
    std::cout << "" << std::endl;
     spielfeld.anzeigen();  
    





    
    //testZelle(spielfeld, 1, 1);

  
    //spielfeld.uncoverAllCells();
    //spielfeld.anzeigen();  

    return 0;
}

void PrintBanner() {
    std::string banner = R"(
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

std::tuple<int, int, int> SelectDifficulty() {
    std::string difficulty;
    std::cout << "Please select difficulty (beginner/advanced/pro): ";
    std::cin >> difficulty;

    if (difficulty == "beginner") {
        return {8, 8, 10}; // Beginner level
    } else if (difficulty == "advanced") {
        return {16, 16, 40}; // Advanced level
    } else if (difficulty == "pro") {
        return {30, 16, 99}; // Professional level
    } else {
        std::cout << "Invalid input, defaulting to beginner.\n";
        return {8, 8, 10}; // Default is beginner level if input is invalid
    }
}

void ClearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape codes to clear the screen
}

void testZelle(Spielfeld& spielfeld, int x, int y) {
    spielfeld.markCell(x, y);
    spielfeld.anzeigen();
    spielfeld.uncoverCell(x, y);
    spielfeld.anzeigen();
    spielfeld.unmarkCell(x, y);
    spielfeld.anzeigen();
    spielfeld.uncoverCell(x, y);
    spielfeld.anzeigen();
}
