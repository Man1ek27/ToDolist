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
    bool once = true;
    localtime_s(&date, &now);
    for(auto i = _list.rbegin(); i != _list.rend() ; ++i){
        if(std::mktime(const_cast<std::tm*>(&i->Get_date())) < std::mktime(&date)){
            (*i).Set_expired();
            if(once) _exp_index = (*i)._lp;
        } 
    }
}

void ToDo::Delete_expired(){
    if(_exp_index < 0){
        return;
    }
    _list.erase(_list.begin(), _list.begin() + _exp_index +1);
}


void ToDo::Print_menu(){
    system("cls");
    std::cout << "Your ToDo list" << std::endl
    << "[1]: Print Your ToDo list" << std::endl
    << "[2]: Add new Task" << std::endl
    << "[3]: Delete Task" << std::endl
    << "[4]: See discription of Task" << std::endl
    << "[5]: Delete expired Tasks" << std::endl
    << "[6]: Clear your ToDo list" << std::endl
    << "[0]: To exit" << std::endl
    << "Choose function: ";  
}

void ToDo::Operation(int decision){
    std::string task;
    std::tm date;
    std::string disc;

    switch(decision){
        case 0:
            system("cls");
            std::cout << "Good bye!!" << std::endl;
            exit(0);
        break;
        case 1:
            system("cls");
            this->Print();
            system("pause");
        break;

        case 2:
            system("cls");
            std::cout << "Insert title of the Task: ";
            std::getline(std::cin >> std::ws, task);

            std::cout << "\nInsert Date of the Task: " << std::endl;
            std::cout << "Year:";
            std::cin >> date.tm_year;

            std::cout << "Month:";
            std::cin >> date.tm_mon;

            std::cout << "Day:";
            std::cin >> date.tm_mday;
            date.tm_mon--;
            std::cout << "Hour:";
            std::cin >> date.tm_hour;

            std::cout << "Minute:";
            std::cin >> date.tm_min;

            std::cout << "\nInsert Discription of the Task: ";
            std::getline(std::cin >> std::ws, disc);

            this->Add(task, date, disc);
            system("pause");

        break;

        case 3:
            system("cls");
            std::cout << "Enter lp of Task u want to delete:";
            int index;
            std::cin >> index;
            this->Delete(index);
            system("pause");

        break;

        case 4:

        break;
        case 5:

        break;

        case 6:

        break;
    }
}





