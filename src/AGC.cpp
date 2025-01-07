#include "AGC.h"
#include <termios.h>
#include <unistd.h>
#include <iostream>

AdvancedGameControl::AdvancedGameControl() {
    // Terminal in den nicht-kanonischen Modus versetzen
    termios newSettings;
    tcgetattr(STDIN_FILENO, &newSettings); // Aktuelle Einstellungen abfragen
    newSettings.c_lflag &= ~ICANON;       // Kanonischen Modus deaktivieren
    newSettings.c_lflag &= ~ECHO;         // Echo deaktivieren (optional)
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings); // Einstellungen anwenden
}

AdvancedGameControl::~AdvancedGameControl() {
    // Terminal-Einstellungen wiederherstellen
    termios defaultSettings;
    tcgetattr(STDIN_FILENO, &defaultSettings); // Aktuelle Einstellungen abfragen
    defaultSettings.c_lflag |= ICANON;        // Kanonischen Modus aktivieren
    defaultSettings.c_lflag |= ECHO;          // Echo aktivieren (optional)
    tcsetattr(STDIN_FILENO, TCSANOW, &defaultSettings); // Einstellungen anwenden
}

char AdvancedGameControl::getInput() {
    return getchar(); // Einzelne Taste ohne Enter lesen
}
