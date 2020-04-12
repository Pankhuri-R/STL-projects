#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

bool is_palindrome(const std::string &str)
{
    std::queue<char>
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
