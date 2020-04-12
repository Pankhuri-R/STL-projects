#include<iostream>
#include<set>
#include<limits>
#include<string>
#include<algorithm>

class Person{
    friend std::ostream &operator<<(std::ostream &os,const Person &p);
private:
    std::string name;
    int age;
public:
    Person(): name{"Unknown"},age{0}
    {}
    Person(std::string name,int age) 
       :name(name),age(age)
       {}
    bool operator<(const Person &p) const{
       return (this->age<p.age);
   }
   
   bool operator==(const Person &p) const{
       return (this->name==p.name&&this->age==p.age);
   }
};

std::ostream &operator<<(std::ostream &os,const Person &p)
{
    os<<p.name<<" "<<p.age<<std::endl;
    return os;
}

template<typename T>
void display(const std::set<T>&l)
{
    std::cout<<"[ ";
    for(auto &elem:l)
        std::cout<<elem<<" ";
    std::cout<<"]"<<std::endl;
}

void test1()
{
    std::set<int>nums{1,4,6,2,8};
    display(nums);
    
    nums={1,1,2,2,3,4,5,6,7,8};
    display(nums);
    
    nums.insert(0);
    nums.insert(9);
    nums.insert(10);
    display(nums);
    
    if(nums.count(5))
        std::cout<<"5 exists in set"<<std::endl;
    else
        std::cout<<"5 not found"<<std::endl;
    
    auto it=nums.find(2);
    if(it!=nums.end())
        std::cout<<"Found: "<<*it<<std::endl;
    
    nums.erase(0);
    display(nums);
    
    nums.clear();
    display(nums);
}

void test2()
{
     std::set<Person>people{
        {"Harry",28},
        {"Ron",27},
        {"Hermione",25}
    };
    display(people);
    
    people.emplace("Nevil",26);
    display(people);
    
    people.emplace("Luna",27);
    display(people);
    
    auto it=people.find(Person{"Ron",27});
    if(it!=people.end())
        people.erase(it);
    display(people);
    
    it=people.find(Person("XXX",25));
    if(it!=people.end())
        people.erase(it);
    display(people); 
}


void test3()
{
    std::set<std::string>alphabets{"A","B","C"};
    display(alphabets);
    
    auto result= alphabets.insert("D");
    display(alphabets);
    
    std::cout<<std::boolalpha;
    std::cout<<"First: "<<*(result.first)<<std::endl;
    std::cout<<"Second: "<<result.second<<std::endl;
    
    result=alphabets.insert("A");
    std::cout<<"First: "<<*(result.first)<<std::endl;
    std::cout<<"Second: "<<result.second<<std::endl;
    
    
}

int main()
{
    std::cout<<"***********Test 1*************"<<std::endl;
    test1();
    std::cout<<"***********Test 2*************"<<std::endl;
    test2();
    std::cout<<"***********Test 3*************"<<std::endl;
    test3();
    return 0;
}
