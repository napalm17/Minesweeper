#include "field.h"

Field::Field(int rows, int cols) : rows(rows), cols(cols), grid(rows, std::vector<Cell>(cols)) {}

bool Field::isInsideGrid(int x, int y) {
    return 0 <= x && x < rows && 0 <= y && y < cols;
}

int Field::getRandomInteger(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

void Field::placeMines(int numMines) {
    int placedMines = 0;

    while (placedMines < numMines) {
        int x = getRandomInteger(0, rows - 1);
        int y = getRandomInteger(0, cols - 1);
        if (!grid[x][y].getMine()) {
            grid[x][y].setMine(true);
            placedMines++;
        }
    }
}

int Field::countNeighborMines(int r, int c) {
    int numMines = 0;
    for (int x = r - 1; x <= r + 1; ++x) {
        for (int y = c - 1; y <= c + 1; ++y) {
            if (isInsideGrid(x, y) && grid[x][y].getMine()) {
                numMines++;
            }
        }
    }
    return numMines;
}

void Field::revealCell(int r, int c) {
    if (isInsideGrid(r, c)) {
        grid[r][c].setNeighborMines(countNeighborMines(r, c));
        grid[r][c].reveal();
    } else {
        std::cout << "Given coordinates are out of bounds" << std::endl;
    }
}

void Field::revealAll() {
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            revealCell(x, y);
        }
    }
}

void Field::toggleMarkCell(int r, int c) {
    if (isInsideGrid(r, c)) {
        grid[r][c].toggleMark();
    } else {
        std::cout << "Given coordinates are out of bounds" << std::endl;
    }
}

void Field::printField() {
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            std::cout << grid[x][y].getSymbol() << " ";
        }
        std::cout << std::endl; // New line for a new row
    }
    std::cout << std::endl;
}

bool Field::hasMine(int x, int y) {
    if (isInsideGrid(x, y)) {
        return grid[x][y].getMine();
    }
    return false;
}

bool Field::areAllCellsCleared() {
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            if ((grid[x][y].isHidden() && !grid[x][y].getMine()) || grid[x][y].isExploded()) {
                return false;
            }
        }
    }
    return true;
}
