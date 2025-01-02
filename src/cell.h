#pragma once
#include <string>
#include <iostream>

class Cell {

private:
    enum State {
        HIDDEN,    // Die Zelle ist verdeckt
        MARKED,    // Die Zelle ist als Mine markiert
        REVEALED,  // Die Zelle ist aufgedeckt
        EXPLODED   // Die Zelle ist explodiert (Mine aufgedeckt)
    };

    State state;           // Aktueller Zustand der Zelle
    bool hasMine;          // Gibt an, ob die Zelle eine Mine enthält
    int neighborMines;     // Anzahl der Minen in den Nachbarzellen

public:
    // Standardkonstruktor
    Cell();

    void setMine(bool mine);
    bool getMine();
    bool isExploded();
    bool isHidden();

    // Setter für die Anzahl der Nachbarminen
    void setNeighborMines(int count);

    std::string getSymbol();
    void print_cell();

    void reveal();
    void toggleMark();
};

