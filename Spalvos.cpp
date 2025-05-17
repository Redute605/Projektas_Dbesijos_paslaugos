//
// Created by Reda on 2025-05-17.
//

#include "Spalvos.h"
#include <windows.h>

class Spalvos {
    static void Pakeisti_Konsoles_Teksto_Spalva (int Spalva) {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, Spalva);

    }

};

