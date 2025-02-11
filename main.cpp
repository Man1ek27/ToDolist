#include <iostream>
#include <locale>
#include <windows.h>
#include <ctime>
#include <limits>

#include "include/Task.hpp"
#include "include/ToDo.hpp"
#include "src/settings.cpp"

int main(void){

    settings();
    ToDo list1;
    
    list1.Read();
    while(1){
        std::cin.clear();
        list1.Print_menu();
        list1.Sort_date();
        list1.Check_if_expired();

        
        int decision = 0;
        std::cin >> decision;
        if(std::cin.fail() || decision >6){
            std::cout << "ERROR: wrong data inserted, try again";
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

        list1.Operation(decision);
        list1.Sort_date();


        list1.Save();
    }
    return 0;
}