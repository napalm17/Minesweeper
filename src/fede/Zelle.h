#pragma once

class Zelle {
public:
    enum Zustand {
        Verdeckt,
        AlsMineMarkiert,
        Aufgedeckt,
        Explodiert
    };

    Zelle();   
    void aufdecken();   
    void markierungUmschalten();  
    void setzeAnzahlMinen(int anzahl);
    char zeichenFuerAnzeige() const;
    bool isMine() const; 
    void setMine();      

private:
    Zustand zustand;
    int angrenzendeMinen;
    bool containsMine;  
};
