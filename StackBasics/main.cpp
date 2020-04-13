#include<iostream>
#include<stack>
#include<algorithm>
#include<list>
#include<vector>

template<typename T>
void display(std::stack<T>s)
{
    std::cout<<"[ ";
    while(!s.empty()){
        T elem=s.top();
        s.pop();
        std::cout<<elem<<" ";
    }
    std::cout<<"]"<<std::endl;
}


int main()
{
    std::stack<int>nums;
    std::stack<std::string,std::vector<int>>s1;
    std::stack<int,std::deque<int>>s2;
    
    for(int i:{1,2,3,4,5})
       nums.push(i);
    
    display(nums);
    
    nums.push(6);
    display(nums);
    
    nums.push(8);
    display(nums);
    
    nums.top()=7;
    display(nums);
    
    nums.pop();
    nums.pop();
    display(nums);
    
    while(!nums.empty())
        nums.pop();
    display(nums);
    
    std::cout<<"Size: "<<nums.size()<<std::endl;
    return 0;
}
