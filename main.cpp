#include <iostream>
#include <locale>
#include <windows.h>
#include <ctime>

#include "include/Task.hpp"


int main(void){

    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(NULL)));


    time_t now = time(0);
    std::tm date;
    localtime_s(&date, &now);


    std::cout << "Śiemą" << std::endl;

    Task first("Praca", date, "nie wiem");
    Task sec("Sporty", date, "tak");
    std::cout << first << std::endl;
    std::cout << sec << std::endl;

    return 0;
}