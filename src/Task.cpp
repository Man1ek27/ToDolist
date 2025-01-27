#include "../include/Task.hpp"

unsigned int Task::_amount=0;

Task::Task(std::string title, std::tm date, std::string disc): _title{title}, _date{date}, _disc{disc}, _lp{++_amount}{
}

std::ostream& operator<<(std::ostream &os, Task &task){
    int titleL = static_cast<int>(task._title.length());
    int first = (18 - 2 - titleL) / 2 +1;
    int sec = (18 - 2 - titleL) / 2 + titleL;
    if(titleL%2 ==1) sec++;

    os << std::setw(20) << std::setfill('=') << "" << std::endl;
    os << std::setfill(' ') 
        << "=" 
        << std::setw(first) << std::right << task._lp << "."
        << std::setw(sec) << std::left  << task._title
        << "=" << std::endl; 
    os << std::setw(20) << std::setfill('=') << "" << std::endl;

    os << std::setw(20) << std::setfill('=') << "" << std::endl;
    os << std::setfill(' ') 
            << "= " <<((task._date.tm_hour <10)?"0":"") << task._date.tm_hour <<":" << ((task._date.tm_hour<10)?"0":"")<< task._date.tm_min << " " 
        <<((task._date.tm_mday <10)?"0":"") << task._date.tm_mday << "." << ((task._date.tm_mon <10)?"0":"") << task._date.tm_mon +1 << "." << task._date.tm_year +1900
        << " =" << std::endl;
    os << std::setw(20) << std::setfill('=') << "" << std::endl;  
    return os;
}



