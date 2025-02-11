#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <functional>
#include <windows.h>

#include "Task.hpp"

class ToDo{
    std::vector<Task> _list;
    
    public:
    int _exp_index = -1;
        void Add(Task &);
        void Add(std::string, std::tm, std::string);
        void Print() const;
        void Delete(int);
        void Clear_all();
        void Save();
        void Read();
        void Discr(int)const;
        void Sort_date();
        void Check_if_expired();
        void Delete_expired();

        void Print_menu();
        void Operation(int);
        

        friend std::ostream &operator<<(std::ostream &, ToDo &);

};