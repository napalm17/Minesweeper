#include "gameplay.h"
#include "utils.h"
#include <iostream>
#include "AGC.h"


GamePlay::GamePlay(Field& field_) : field(field_), isGameOver(false) {}

void GamePlay::placeMines(int numMines) {
    int placedMines = 0;
    while (placedMines < numMines) {
        int x = Utils::getRandomInteger(0, field.rows - 1);
        int y = Utils::getRandomInteger(0, field.cols - 1);
        if (!field.hasMine(x, y)) {
            field.setMine(x, y, true);
            placedMines++;
        }
    }
}

void GamePlay::toggleMarkCell(int x, int y) {
    field.toggleMarkCell(x, y);
}

void GamePlay::revealCell(int x, int y) {
    field.revealNeighborCells(x, y);
    if (field.hasMine(x, y)) {
        isGameOver = true;
        field.revealAll();
        field.printField();
        std::cout << "\nGame over, you lost.\n" << std::endl;
    } else if (field.areAllCellsCleared()) {
        isGameOver = true;
        std::cout << "\nGame over, you won.\n" << std::endl;
    }
}

void GamePlay::runGame() {
    while (!(isGameOver)) {
        std::string command = Utils::parseCommand();
        int x = Utils::parseSingleInt("row");
        int y = Utils::parseSingleInt("column");
        if (command == "m") {
            toggleMarkCell(x, y);
        } else if (command == "r") {
            revealCell(x, y);
        } else {
            std::cout << "Given Command is invalid, try again."  << std::endl;;
        }
        field.printField();
    }
}

void GamePlay::runGame2() {
    int x = 0;
    int y = 0;
    AdvancedGameControl gameControl;
    char input;
    while (!(isGameOver)) {
        x = ((x % field.rows) + field.rows) % field.rows;
        y = ((y % field.cols) + field.cols) % field.cols;
        field.highlightCell(x, y);
        field.printField();
        input = gameControl.getInput();
        switch (input) {
            case 'm':
                toggleMarkCell(x, y);
                break;
            case 'r':
                revealCell(x, y);
                break;
            case 'w':
                x--;
                break;
            case 's':
                x++;
                break;
            case 'a':
                y--;
                break;
            case 'd':
                y++;
                break;
        }
    }
}





