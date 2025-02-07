#pragma once 
#include <iostream>
#include <vector>
#include <string>

#include "Task.hpp"

class ToDo: Task{
    std::vector<Task> _list;

    public:
        void Add(Task &);
        void Print() const;
        void Delete(int);
        void Clear_all();

};