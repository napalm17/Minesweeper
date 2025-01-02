#include "cell.h"

// Standardkonstruktor
Cell::Cell() : state(HIDDEN), hasMine(false), neighborMines(0) {}

void Cell::setMine(bool mine) {
    hasMine = mine;
}

bool Cell::getMine() {
    return hasMine;
}

bool Cell::isExploded() {
    return state == EXPLODED;
}

bool Cell::isHidden() {
    return state == HIDDEN;
}

void Cell::setNeighborMines(int count) {
    neighborMines = count;
}

std::string Cell::getSymbol() {
    switch (state) {
        case HIDDEN:
            return "■";
        case MARKED:
            return "⚑";
        case REVEALED:
            if (hasMine) {
                return "*";
            }
            if (neighborMines > 0) {
                return std::to_string(neighborMines);
            }
            return "□";

        case EXPLODED:
            return "X";
    }
    return "?";
}

void Cell::print_cell() {
    std::cout << getSymbol() << std::endl;
}

void Cell::reveal() {
    if (state == MARKED) {
        std::cout << "Die Zelle ist markiert und kann nicht aufgedeckt werden." << std::endl;
        return;
    }
    if (hasMine) {
        state = EXPLODED; // Zelle explodiert, wenn sie eine Mine enthält
    } else {
        state = REVEALED; // Zelle wird aufgedeckt
    }
}

void Cell::toggleMark() {
    if (state == HIDDEN) {
        state = MARKED; // Markiere die Zelle als Mine
    } else if (state == MARKED) {
        state = HIDDEN; // Entferne die Markierung
    } else {
        std::cout << "Markierung kann nur auf verdeckten Zellen geändert werden." << std::endl;
    }
}
