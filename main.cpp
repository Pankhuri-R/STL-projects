#include<iostream>
#include<set>
#include<map>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<algorithm>

void display_words(std::map<std::string,int>&m)
{
    std::cout<<std::setw(12)<<std::left<<"\nWORD"
                  <<std::setw(20)<<std::right<<"COUNT"<<std::endl;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    for(const auto &elem:m){
        std::cout<<std::setw(12)<<std::left<<elem.first
                      <<std::setw(20)<<std::right<<elem.second<<std::endl;
    }
}

void display_words(std::map<std::string,std::set<int>>&m)
{
    std::cout<<std::setw(12)<<std::left<<"\nWORD"
                  <<std::setw(20)<<std::right<<"OCCURRENCES"<<std::endl;
    std::cout<<"----------------------------------------------------------"<<std::endl;
    for(const auto &elem:m){
        std::cout<<std::setw(12)<<std::left<<elem.first<<"[ ";
        for(const auto &i:elem.second)
            std::cout<<i<<" ";
        std::cout<<"]"<<std::endl;
    }
}

std::string clean_string(const std::string &s){
    std::string result;
    for(char c:s){
        if(c=='.' || c==',' || c=='?' || c=='!')
            continue;
        else
            result+=c;
    }
    return result;
}

void part1()
{
    std::map<std::string,int>words;
    std::string line;
    std::string word;
    std::ifstream in_file("ThirstyCrow.txt");
    if(in_file){
        while(std::getline(in_file,line)){
            std::stringstream ss(line);
            while(ss>>word){
                word=clean_string(word);
                words[word]++;
            }
        }
        in_file.close();
        display_words(words);
    }
    else
        std::cerr<<"Error opening the file"<<std::endl;
}

void part2()
{
    std::map<std::string,std::set<int>>words;
    std::string line;
    std::string word;
    std::ifstream in_file("ThirstyCrow.txt");
    if(in_file){
        int line_number{0};
        while(std::getline(in_file,line)){
            line_number++;
            std::stringstream ss(line);
            while(ss>>word){
                word=clean_string(word);
                words[word].insert(line_number);
                
            }
        }
        in_file.close();
        display_words(words);
    }
    else
        std::cerr<<"Error opening the file"<<std::endl; 
}

int main()
{
    part1();
    part2();
    return 0;
}
