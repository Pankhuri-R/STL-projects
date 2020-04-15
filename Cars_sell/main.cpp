#include<iostream>
#include<list>
#include<algorithm>
#include<map>
#include<iomanip>
#include<cctype>

void display_menu()
{
    std::cout<<"\n\nD-Duster"<<std::endl;
    std::cout<<"S-Safari"<<std::endl;
    std::cout<<"B-BMW"<<std::endl;
    std::cout<<"A-Add a new car and calculate its value"<<std::endl;
    std::cout<<"L-Display the list"<<std::endl;
    std::cout<<"Q-Quit"<<std::endl;
    std::cout<<"*************************"<<std::endl;
    
}

void display(std::map<std::string,int>&m){
    std::cout<<std::setw(15)<<std::left<<"Car"
                     <<std::setw(15)<<std::right<<"Number"<<std::endl;
    std::cout<<"-------------------------------------"<<std::endl;
    for(auto elem:m){
        std::cout<<std::setw(15)<<std::left<<elem.first
                     <<std::setw(15)<<std::right<<elem.second<<std::endl;
    }
}

int main()
{
    std::map<std::string,int>cars
    {
        {"Duster",6},
        {"Safari",7},
        {"BMW",3}
    };
    char selection{};
    do{
    display_menu();
    std::cout<<"Select one of the option in menu:";
    
    std::cin>>selection;
    long double value{};
    double price{};
    
    selection=std::toupper(selection);
    if(selection=='D'){
        std::cout<<"Also enter the price for that model: ";
         std::cin>>price;
        value=price*6;
        std::cout<<"Value for the model is "<<value<<std::endl;
    }
    else if(selection=='S'){
        std::cout<<"Also enter the price for that model: ";
        std::cin>>price;
        value=price*7;
        std::cout<<"Value for the model is "<<value<<std::endl;
    }
    else if(selection=='B'){
        std::cout<<"Also enter the price for that model: ";
         std::cin>>price;
        value=price*3;
        std::cout<<"Value for the model is "<<value<<std::endl;
    }
    else if(selection=='A')
    {
        std::string name;
        int val;
        std::cout<<"Enter the name of the car: ";
        std::cin>>name;
        std::cout<<"Enter the numbers of cars sold: ";
        std::cin>>val;
        cars.insert(std::make_pair(name,val));
         std::cout<<"Also enter the price for that model: ";
         std::cin>>price;
         value=price*val;
        std::cout<<"Value for the model is "<<value<<std::endl;
    }
    else if(selection=='L')
        display(cars);
    
    else if(selection=='Q')
        std::cout<<"Quitting....Please wait...."<<std::endl;
    
    }while(selection!='Q');
    std::cout<<std::endl;
    return 0;
}
