#include "../include/ToDo.hpp"

void ToDo::Add(Task &tsk){
    _list.push_back(tsk);
}

void ToDo::Add(std::string title, std::tm data, std::string disc){
    Task temp(title, data, disc);
    this->Add(temp);
}


void ToDo::Print()const{
    if(_list.empty()){
        std::cout << "PUSTO!" << std::endl;
        return;
    }

    int k=1;
    for(Task i : _list){
        i._lp = k++;
        std::cout << i << std::endl;
    }
}

void ToDo::Delete(int index){
    _list.erase(_list.begin() + index -1);
}


void ToDo::Clear_all(){
    _list.clear();
}


std::ostream &operator<<(std::ostream &os, ToDo &todo){
    for( Task i : todo._list){
        os << i.Get_title() << "\t" 
        << i.Get_date().tm_hour <<" " << i.Get_date().tm_min <<" " << i.Get_date().tm_mday <<" " << i.Get_date().tm_mon+1 <<" "<< i.Get_date().tm_year+1900
        << "\t" << i.Get_disc() << std::endl;
    }
    return os;
}

void ToDo::Save(){
    std::ofstream File("../../Save_list/saves.txt");
    if(!File.good()){
        std::cout << "BŁĄD zapisu" << std::endl;
    }
    File << *this;
    std::cout << "done" << std::endl;
}
   

void ToDo::Read(){
    std::ifstream File("../../Save_list/saves.txt");
    std::string data;
    while (std::getline(File, data)){
        std::stringstream ss(data);
        std::string one_data;
        char dilimiter = '\t';

        std::vector<std::string> one;

        while(std::getline(ss, one_data, dilimiter)){
            one.push_back(one_data);
        }
        
        std::tm date = {};

        std::istringstream is(one[1]);

        is >> std::get_time(&date, "%H %M %d %m %Y");

        this->Add(one[0], date, one[2]);
        
    }
}

void ToDo::Discr(int index)const{
     std::cout << _list[index];
    
    _list[index].PrintDisc();
}


void ToDo::Sort_date(){
    std::sort(_list.begin(), _list.end(), [](const Task &a, const Task &b) {
        return std::mktime(const_cast<std::tm*>(&a.Get_date())) < std::mktime(const_cast<std::tm*>(&b.Get_date()));
    });
}


void ToDo::Check_if_expired(){
    bool expired = false;
    time_t now = time(0);
    std::tm date;
    localtime_s(&date, &now);
    for(auto i = _list.rbegin(); i != _list.rend() ; ++i){
        if(std::mktime(const_cast<std::tm*>(&i->Get_date())) < std::mktime(&date)){
            (*i).Set_expired();
        } 
    }
    
}



