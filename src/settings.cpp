#include <iostream>
#include <locale>
#include <windows.h>
#include <ctime>

void settings(){
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(NULL)));

    time_t now = time(0);
    std::tm date;
    localtime_s(&date, &now);
}

