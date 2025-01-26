#pragma once 
#include <iostream>
#include <ctime>

class Task{
    std::string _title;
    std::tm _date;
    std::string _disc;

    public:
        static unsigned int _lp;
        Task() = default;
        Task(std::string, std::tm, std::string);

        void Print();
        friend std::ostream &operator<<(std::ostream, std::tm);
};