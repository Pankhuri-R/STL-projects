#include<iostream>
#include<algorithm>
#include<deque>
#include<iomanip>
#include<cctype>
#include<vector>
#include<cstring>

bool is_palindrome(const std::string &str)
{
   std::deque<char>d;
   
   for(auto s:str){
       if(std::isalpha(s))
              d.push_back(std::toupper(s));
   }
    char c1{};
    char c2{};
    
   while(d.size()>1){
       c1=d.front();
       c2=d.back();
       d.pop_back();
       d.pop_front();
       if(c1!=c2)
           return false;
   }
    return true;
}

int main()
{
    std::vector<std::string>test_strings{"a","aa","aba","abba","abcba","ab","abc","radar","bob","ana","avid diva","amore,roma","A Toyota's a toyota","A Santa at NASA",
    "C++","Palindrome"};
    std::cout<<std::boolalpha;
    std::cout<<std::setw(8)<<std::left<<"RESULT"<<"String"<<std::endl;
    for(const auto &s:test_strings)
        std::cout<<std::setw(8)<<std::left<<is_palindrome(s)<<s<<std::endl;
    std::cout<<std::endl;
    return 0;
}
