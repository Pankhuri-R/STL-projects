#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<iterator>

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
    bool operator>(const Person &p) const{
       return (this->age>p.age);
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
void display(const std::list<T>&l)
{
    std::cout<<"[ ";
    for(auto &elem:l)
        std::cout<<elem<<" ";
    std::cout<<"]"<<std::endl;
}

void test1()
{
    std::list<int>nums{1,2,3,4,5};
    display(nums);
    
    nums.push_back(6);
    nums.push_front(0);
    display(nums);
    
    std::cout<<"Size: "<<nums.size()<<std::endl;
}

void test2()
{
    std::list<double>decimals{9.5,8.7,4.9,2.4,5.5};
    display(decimals);
    std::cout<<"Size: "<<decimals.size()<<std::endl;
    std::cout<<"Front: "<<decimals.front()<<std::endl;
    std::cout<<"Back: "<<decimals.back()<<std::endl;
    
    decimals.clear();
    display(decimals);
}

void test3()
{
    std::list<Person>people{{"Harry",50},{"Ron",30},{"Hermione",100}};
    display(people);
    
    people.pop_front();
    display(people);
    
    std::list<int>nums{1,2,3,4,5,6,7,8};
    display(nums);
    nums.resize(2);
    display(nums);
    nums.resize(8);
    display(nums);
    
    people.resize(2);
    display(people);
    
    people.resize(5);
    display(people);
}

void test4()
{
    std::list<int>nums1{1,2,3,4,5,7,8};
    std::list<int>nums2{100,200,300,400,500};
    display(nums1);
    display(nums2);
    
    auto it=std::find(nums1.begin(),nums1.end(),7);
    if(it!=nums1.end()){
        nums1.insert(it,6);
    }
    display(nums1);
    
    auto it1=std::find(nums1.begin(),nums1.end(),7);
    if(it1!=nums1.end()){
        nums1.insert(it1,nums2.begin(),nums2.end());
    }
    display(nums1);
    
    std::advance(it,-2);
    std::cout<<*it<<std::endl;
    
    nums1.erase(it);
    display(nums1);
}

void test5()
{
    std::list<Person>stooges{{"Monica",25},{"Ross",28},{"Chandler",29}};
    display(stooges);
    
    std::string name;
    int age;
    std::cout<<"Enter the name of another person: ";
    getline(std::cin,name);
    std::cout<<"Enter his/her age: ";
    std::cin>>age;
    
    stooges.emplace_back(Person(name,age));
    display(stooges);
    
    auto it=std::find(stooges.begin(),stooges.end(),Person{"Ross",28});
    if(it!=stooges.end()){
        stooges.emplace(it,Person {"Rachel",27});
    }
    display(stooges);
}

void test6()
{
    std::list<Person>stooges{{"Chan",97},{"Monica",100},{"Rach",50}};
    display(stooges);
    stooges.sort();
    display(stooges);
}

int main()
{
    std::cout<<"***********Test 1*************"<<std::endl;
    test1();
    std::cout<<"***********Test 2*************"<<std::endl;
    test2();
    std::cout<<"***********Test 3*************"<<std::endl;
    test3();
    std::cout<<"***********Test 4*************"<<std::endl;
    test4();
    std::cout<<"***********Test 5*************"<<std::endl;
    test5();
    std::cout<<"***********Test 6*************"<<std::endl;
    test6();
    return 0;
}
