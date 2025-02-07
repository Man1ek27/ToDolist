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

