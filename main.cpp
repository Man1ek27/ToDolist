#include <iostream>
#include <locale>
#include <windows.h>
#include <ctime>

#include "include/Task.hpp"


int main(void){

    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    SYSTEMTIME sysTime;
    GetLocalTime(&sysTime);

    std::tm date = {};
    date.tm_year = sysTime.wYear - 1900; // Year since 1900
    date.tm_mon = sysTime.wMonth - 1;   // 0-based month
    date.tm_mday = sysTime.wDay;
    date.tm_hour = sysTime.wHour;
    date.tm_min = sysTime.wMinute;
    date.tm_sec = sysTime.wSecond;

    std::cout << "Śiemą" << std::endl;

    Task("Praca", date, "nie wiem");
    return 0;
}