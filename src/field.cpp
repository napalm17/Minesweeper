#include "field.h"

Field::Field(int rows, int cols) : rows(rows), cols(cols), grid(rows, std::vector<Cell>(cols)), highlightX(0), highlightY(0)  {
    grid[highlightX][highlightY].setHighlight(true); 
}

bool Field::isInsideGrid(int x, int y) {
    return 0 <= x && x < rows && 0 <= y && y < cols;
}

int Field::getRandomInteger(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

void Field::setMine(int x, int y, bool value) {
    grid[x][y].setMine(value);
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

void Field::revealNeighborCells(int r, int c) {
    // Ensure the current cell is valid and safe
    if (!isInsideGrid(r, c) || !grid[r][c].isHidden() || grid[r][c].getMine()) {
        return;
    }

    // Reveal the current cell
    revealCell(r, c);

    // If this cell has neighboring mines, stop further recursion
    if (countNeighborMines(r, c) > 0) {
        return;
    }

    // Process neighboring cells iteratively to avoid recursion depth issues
    for (int x = r - 1; x <= r + 1; ++x) {
        for (int y = c - 1; y <= c + 1; ++y) {
            if (isInsideGrid(x, y) && !(x == r && y == c)) {
                // Recursive call for valid neighbor
                revealNeighborCells(x, y);
            }
        }
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
    for (int i = 0; i < 50; ++i) {
        std::cout << std::endl;
    }
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            std::cout << grid[x][y].getSymbol() << " ";
        }
        std::cout << std::endl; // New line for a new row
    }

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

void Field::highlightCell(int x, int y) {
    grid[highlightX][highlightY].setHighlight(false);
    grid[x][y].setHighlight(true);
    highlightX = x;
    highlightY = y;
    }
