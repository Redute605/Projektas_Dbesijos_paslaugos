//
// Created by Reda on 2025-05-18.
//

#include "Spalvos.h"


void Spalvos::Pakeisti_Konsolės_Teksto_Spalva(int Spalva) {
    HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, Spalva);
}
