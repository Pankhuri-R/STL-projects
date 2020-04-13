#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cctype>
#include<iomanip>

bool is_palindrome(const std::string &str)
{
    std::queue<char>q;
    std::stack<char>s;
    
    for(auto &i:str){
        if(std::isalpha(i))
            q.push(std::toupper(i));
            s.push(std::toupper(i));
    }
    char c1=q.front();
    char c2=s.top();
  
  while(q.size()>1){
      q.pop();
      s.pop();
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
    std::cout<<std::setw(15)<<std::left<<"RESULT"<<"String"<<std::endl;
    for(const auto &s:test_strings)
        std::cout<<std::setw(15)<<std::left<<is_palindrome(s)<<s<<std::endl;
    std::cout<<std::endl;
    return 0;
}
