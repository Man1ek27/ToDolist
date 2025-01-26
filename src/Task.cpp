#include "../include/Task.hpp"

unsigned int Task::_lp=0;

Task::Task(std::string title, std::tm date, std::string disc): _title{title}, _date{date}, _disc{disc}{
    _lp++;
}

std::ostream& operator<<(std::ostream &os, std::tm date){
    os << date.tm_mday << "." << date.tm_mon << "." << date.tm_year;
    return os;
}



void Task::Print(){
    std::cout << "===========================" << std::endl;
    std::cout << "=       " << this->_lp <<". " << this->_title << "        =" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "=       " << _date << "      =" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "=  " << _disc << "  =" << std::endl; 
}