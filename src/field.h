#pragma once
#include <vector>
#include <iostream>
#include "cell.h"
#include <random>

class Field {
private:

    std::vector<std::vector<Cell>> grid;

    bool isInsideGrid(int x, int y);
    int getRandomInteger(int min, int max);
    

public:
    int highlightX, highlightY;
    int rows;
    int cols;
    Field(int rows, int cols);
    void setMine(int x, int y, bool value);
    void placeMines(int numMines);
    int countNeighborMines(int r, int c);
    void revealCell(int r, int c);
    void revealAll();
    void toggleMarkCell(int r, int c);
    void printField();
    bool hasMine(int x, int y);
    bool areAllCellsCleared();
    void highlightCell(int x, int y);
};