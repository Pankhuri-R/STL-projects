#include<iostream>
#include<queue>
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
      // return (this->age<p.age);
       return this->name<p.name;
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
void display(std::priority_queue<T>pq)
{
    std::cout<<"[ ";
    while(!pq.empty()){
        T elem=pq.top();
        pq.pop();
        std::cout<<elem<<" ";
    }
    std::cout<<"]"<<std::endl;
}

int main()
{
    std::cout<<"******************Test 1*****************"<<std::endl;
    std::priority_queue<int>nums;
    
    for(int i:{10,20,30,5,9,6,100,76})
        nums.push(i);
    display(nums);
    
    std::cout<<"Size: "<<nums.size()<<std::endl;
    std::cout<<"Top: "<<nums.top()<<std::endl;
    
    
    nums.pop();
    display(nums);
    
     std::cout<<"******************Test 2*****************"<<std::endl;
     std::priority_queue<Person>pq;
     
     pq.push(Person{"Ana",24});
     pq.push(Person{"Christian",28});
      pq.push(Person{"Teddy",8});
     
     display(pq);
    return 0;
}
