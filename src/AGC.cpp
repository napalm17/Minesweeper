#include "AGC.h"
#include <termios.h>
#include <unistd.h>
#include <iostream>

AdvancedGameControl::AdvancedGameControl() {
    // Terminal in den nicht-kanonischen Modus versetzen
    termios newSettings;
    tcgetattr(STDIN_FILENO, &newSettings);
    newSettings.c_lflag &= ~ICANON;      
    newSettings.c_lflag &= ~ECHO;         
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}

AdvancedGameControl::~AdvancedGameControl() {
    // Terminal-Einstellungen wiederherstellen
    termios defaultSettings;
    tcgetattr(STDIN_FILENO, &defaultSettings);
    defaultSettings.c_lflag |= ICANON;       
    defaultSettings.c_lflag |= ECHO;       
    tcsetattr(STDIN_FILENO, TCSANOW, &defaultSettings);
}

char AdvancedGameControl::getInput() {
    return getchar(); // Einzelne Taste ohne Enter lesen
}
