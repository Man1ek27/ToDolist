#include "../include/ToDo.hpp"

void ToDo::Add(Task &tsk){
    _list.push_back(tsk);
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
        << i.Get_date().tm_hour <<" " << i.Get_date().tm_min <<" " << i.Get_date().tm_mday <<" " << i.Get_date().tm_mon <<" "<< i.Get_date().tm_year
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
   

