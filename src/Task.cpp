#include "../include/Task.hpp"

unsigned int Task::_amount=0;

Task::Task(std::string title, std::tm date, std::string disc): _title{title}, _date{date}, _disc{disc}, _lp{++_amount}{
}

std::ostream& operator<<(std::ostream &os, const Task &task){
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
    
    os << std::setfill(' ') 
            << "= " <<((task._date.tm_hour <10)?"0":"") << task._date.tm_hour <<":" << ((task._date.tm_hour<10)?"0":"")<< task._date.tm_min << " " 
        <<((task._date.tm_mday <10)?"0":"") << task._date.tm_mday << "." << ((task._date.tm_mon <10)?"0":"") << task._date.tm_mon +1 << "." << task._date.tm_year +1900
        << " =" << std::endl;
    os << std::setw(20) << std::setfill('=') << "" << std::endl;  
    return os;
}


void Task::PrintDisc(){
    std::istringstream iss(_disc);
    std::string word;

    std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;

    std::cout << "=  ";
    unsigned int letters_left = 34;
    while (iss >> word)
    {
        if(word.size() > letters_left){
            //std::cout << letters_left << "  " << word.size();  
            std::cout  << std::setw(letters_left+3) << std::setfill(' ') << std::right  << " ="<<std::endl << "=  ";
            letters_left = 34;
        }
        std::cout << word << " ";
        letters_left -= static_cast<int>(word.size()) +1;
    }
    std::cout  << std::setw(letters_left+3) << std::setfill(' ') << std::right  << " ="<<std::endl;
    std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;
}



