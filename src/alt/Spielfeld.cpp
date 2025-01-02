#include "Spielfeld.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


Spielfeld::Spielfeld(int breite, int hoehe, int minen) : breite(breite), hoehe(hoehe) {
    raster.resize(hoehe, std::vector<Zelle>(breite));
    std::srand(std::time(nullptr));
    // platziere minen
    for (int i = 0; i < minen; i++) {
        int x, y;
        do {
            x = std::rand() % breite;
            y = std::rand() % hoehe;
        } while (raster[y][x].isMine());
        raster[y][x].setMine();
    }
    // berechne # benachbarte minen
    calculateAdjacentMines();
}


void Spielfeld::anzeigen() const {
    for (const auto& zeile : raster) {    //iterator
        for (const auto& zelle : zeile) {
            std::cout << zelle.zeichenFuerAnzeige() << " ";
        }
        std::cout << "\n";
    }
}

void Spielfeld::uncoverAllCells() {
    for (auto& row : raster) {
        for (auto& cell : row) {
            cell.aufdecken();
        }
    }
}

void Spielfeld::uncoverCell(int x, int y) {
    if (x >= 0 && x < breite && y >= 0 && y < hoehe) {
        raster[y][x].aufdecken();
    }
}

void Spielfeld::markCell(int x, int y) {
    if (x >= 0 && x < breite && y >= 0 and y < hoehe) {
        raster[y][x].markierungUmschalten();
    }
}

void Spielfeld::unmarkCell(int x, int y) {
    if (x >= 0 && x < breite && y >= 0 && y < hoehe) {
        raster[y][x].markierungUmschalten();
    }
}

char Spielfeld::zeichenFuerAnzeige(int x, int y) const {
    return raster[y][x].zeichenFuerAnzeige();
}

void Spielfeld::calculateAdjacentMines() {
    for (int y = 0; y < hoehe; ++y) {
        for (int x = 0; x < breite; ++x) {
            if (!raster[y][x].isMine()) { // nur wenn Zelle keine Mine ist
                int count = 0;
                // Prüfe alle benachbarten Zellen
                for (int dy = -1; dy <= 1; ++dy) {
                    for (int dx = -1; dx <= 1; ++dx) {
                        int ny = y + dy;
                        int nx = x + dx;
                        // Prüft dass man nicht zu weit geht
                        if (ny >= 0 && ny < hoehe && nx >= 0 && nx < breite) {
                            if (raster[ny][nx].isMine()) {
                                count++;
                            }
                        }
                    }
                }
                raster[y][x].setzeAnzahlMinen(count);
            }
        }
    }
}
