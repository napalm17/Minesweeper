#pragma once
#include <vector>
#include <iostream>
#include "cell.h"
#include <random>

class Field {
private:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> grid;

    bool isInsideGrid(int x, int y);
    int getRandomInteger(int min, int max);

public:
    Field(int rows, int cols);

    void placeMines(int numMines);
    int countNeighborMines(int r, int c);
    void revealCell(int r, int c);
    void revealAll();
    void toggleMarkCell(int r, int c);
    void printField();
    bool hasMine(int x, int y);
    bool areAllCellsCleared();
};