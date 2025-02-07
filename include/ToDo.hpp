#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Task.hpp"

class ToDo: Task{
    std::vector<Task> _list;

    public:
        void Add(Task &);
        void Print() const;
        void Delete(int);
        void Clear_all();
        void Save();

        friend std::ostream &operator<<(std::ostream &, ToDo &);

};