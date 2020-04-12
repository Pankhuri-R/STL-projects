#include<iostream>
#include<queue>
#include<stack>

template<typename T>
void display(std::queue<T>q)
{
    std::cout<<"[ ";
    while(!q.empty()){
        T elem=q.front();
        q.pop();
        std::cout<<elem<<" ";
    }
    std::cout<<"]"<<std::endl;
}

int main()
{
    std::queue<int>nums;
    
    for(int i:{1,2,3,4,5})
        nums.push(i);
    display(nums);
    
    std::cout<<"Front: "<<nums.front()<<std::endl;
    std::cout<<"Back: "<<nums.back()<<std::endl;
    
    nums.pop();
    nums.pop();
    display(nums);
    
    while(!nums.empty())
        nums.pop();
    display(nums);
    
    nums.push(1000);
    nums.push(50);
    nums.push(24);
    display(nums);
    
    nums.back()=100;
    display(nums);
    return 0;
}
