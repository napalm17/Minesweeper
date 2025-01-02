#pragma once
#include <vector>
#include "Zelle.h"

class Spielfeld {
public:
    Spielfeld(int breite, int hoehe, int minen);
    void anzeigen() const;
    void uncoverCell(int x, int y);  
    void markCell(int x, int y);
    void unmarkCell(int x, int y);
    void uncoverAllCells();
    char zeichenFuerAnzeige(int x, int y) const;

private:
    std::vector<std::vector<Zelle>> raster;
    int breite, hoehe;
};
