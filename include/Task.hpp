#pragma once 
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>

class Task{
    std::string _title;
    std::tm _date;
    std::string _disc;

    public:
        static unsigned int _amount;
        unsigned int _lp;
        Task() = default;
        Task(std::string, std::tm, std::string);

        friend std::ostream &operator<<(std::ostream &, const Task &);

        void PrintDisc();
};