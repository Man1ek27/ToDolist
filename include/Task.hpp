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
    bool _expired = false;

    public:
        static unsigned int _amount;
        unsigned int _lp;
        Task() = default;
        Task(std::string, std::tm, std::string);

        friend std::ostream &operator<<(std::ostream &, const Task &);

        void PrintDisc()const;

        std::string Get_title();
        std::tm Get_date()const;
        std::string Get_disc();

        void Set_expired();

};