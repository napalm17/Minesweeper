#include "Zelle.h"

Zelle::Zelle() : zustand(Verdeckt), angrenzendeMinen(0), containsMine(false) {} 

void Zelle::aufdecken() {
    if (containsMine) {
        zustand = Explodiert;
    } else if (zustand == Verdeckt || zustand == AlsMineMarkiert) {
        zustand = Aufgedeckt;
    }
}

void Zelle::markierungUmschalten() {
    if (zustand == Verdeckt) {
        zustand = AlsMineMarkiert;
    } else if (zustand == AlsMineMarkiert) {
        zustand = Verdeckt;
    }
}

void Zelle::setzeAnzahlMinen(int anzahl) {
    angrenzendeMinen = anzahl;
}

char Zelle::zeichenFuerAnzeige() const {
    switch (zustand) {
        case Verdeckt:
            return '*';  
        case AlsMineMarkiert:
            return '!';  
        case Aufgedeckt:
            if (containsMine) {
                return '#';  
            } else {
                return (angrenzendeMinen > 0) ? '0' + angrenzendeMinen : '0';  
            }
        case Explodiert:
            return '#';  
    }
    return '?';  
}



bool Zelle::isMine() const {
    return containsMine;
}

void Zelle::setMine() {
    containsMine = true;
}
