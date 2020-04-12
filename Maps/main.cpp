#include<iostream>
#include<set>
#include<map>

void display(std::map<std::string,std::set<int>>&m)
{
    std::cout<<"[ ";
    for(const auto &elem:m){
        std::cout<<elem.first<<": [ ";
        for(const auto &set_elem:elem.second){
            std::cout<<set_elem<<" ";
        }
        std::cout<<"]";
    }
    std::cout<<"]"<<std::endl;
}

template<typename T1,typename T2>
void display(std::map<T1,T2> &m)
{
    std::cout<<"[ ";
    for(const auto &elem:m)
        std::cout<<elem.first<<": "<<elem.second<<" ";
    std::cout<<"]"<<std::endl;
}

void test1()
{
    std::map<std::string,int>m{
        {"Harry",65},
        {"Hermione",100},
        {"Ron",50}
    };
    
    display(m);
    
    m.insert(std::pair<std::string,int>("Nevil",75));
    display(m);
    
    m.insert(std::make_pair("Luna",88));
    display(m);
    
    m["Joe"]=40;
    display(m);
    
    m["Joe"]+=15;
    display(m);
    
    m.erase("Joe");
    display(m);
    
    std::cout<<"Count for joe: "<<m.count("Joe")<<std::endl;
    std::cout<<"Count for Luna: "<<m.count("Luna")<<std::endl;
    
    auto it=m.find("Harry");
    if(it!=m.end())
        std::cout<<"Found "<<it->first<<": "<<it->second<<std::endl;
    
    m.clear();
    display(m);
}


void test2()
{
    std::map<std::string,std::set<int>>grades{
        {"Larry",{96,99}},
        {"Moe",{78,65,43}},
        {"Curly",{85,89}}
    };
    display(grades);
    
    grades["Larry"].insert(100);
    display(grades);
    
    auto it= grades.find("Moe");
    if(it!=grades.end())
        it->second.insert(55);
    display(grades);
}

int main()
{
    std::cout<<"***********Test 1*************"<<std::endl;
    test1();
    std::cout<<"***********Test 2*************"<<std::endl;
    test2();
    return 0;
}
