#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

#include "Task.hpp"

class ToDo: Task{
    std::vector<Task> _list;

    public:
        void Add(Task &);
        void Add(std::string, std::tm, std::string);
        void Print() const;
        void Delete(int);
        void Clear_all();
        void Save();
        void Read();
        

        friend std::ostream &operator<<(std::ostream &, ToDo &);

};