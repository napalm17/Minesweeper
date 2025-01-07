#pragma once
#include "field.h"

class GamePlay {
private:
    Field& field;
    bool isGameOver;

public:
    GamePlay(Field& field);
    void runGame();
    void runGame2();
    void placeMines(int numMines);
    void toggleMarkCell(int x, int y);
    void revealCell(int x, int y);

};