#include <iostream>
#include <locale>
#include <windows.h>
#include <ctime>

#include "include/Task.hpp"
#include "include/ToDo.hpp"


int main(void){

    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(NULL)));


    time_t now = time(0);
    std::tm date;
    localtime_s(&date, &now);

    ToDo list1;


    // Task first("Praca", date, "zrobic rozliczanie na nowy samochod i kilka innych rzeczy");
    //     Task sec("Sport", date, "bieganie");
    // // for(int i=0; i <5; i++){
    // //     list1.Add(sec);
    // // }
    // // std::cout << first << std::endl;
    // // std::cout << sec << std::endl;
    // list1.Add(first);
    // list1.Add(sec);

    

    //first.PrintDisc();
    list1.Read();
    list1.Print();

    list1.Discr(0);
    
    list1.Save();
    return 0;
}