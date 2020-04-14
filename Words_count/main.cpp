#include<iostream>
#include<map>
#include<set>
#include<iomanip>
#include<algorithm>
#include<fstream>
#include<sstream>


void display(std::map<std::string,int>m)
{
    std::cout<<std::setw(17)<<std::left<<"\nWORD"
                 <<std::setw(27)<<std::right<<"COUNT"<<std::endl;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    for(auto elem:m){
        std::cout<<std::setw(17)<<std::left<<elem.first
                      <<std::setw(27)<<std::right<<elem.second<<std::endl;
    }    
    std::cout<<std::endl;
}

void display(std::map<std::string,std::set<int>>m)
{
    std::cout<<std::setw(17)<<std::left<<"\nWORD"
                  <<std::setw(27)<<std::right<<"OCCURRENCES"<<std::endl;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    for(auto elem:m){
        std::cout<<std::setw(17)<<std::left<<elem.first;
        std::cout<<"[ ";
        for(auto i:elem.second){
            std::cout<<std::setw(27)<<std::right<<i<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
}

std::string clean_string(std::string &s)
{
    std::string str;
    for(auto &c:s){
        if(std::isalpha(c))
            str+=c;
        else
            continue;
    }
    return str;
}

void part1()
{
    std::map<std::string,int>words;
    std::ifstream in_file("ThirstyCrow.txt");
    if(!in_file)
        std::cerr<<"Couldn't open the file"<<std::endl;
    else{
        std::string line{};
        std::string word{};
        while(std::getline(in_file,line)){
            std::stringstream ss(line);
            while(ss>>word){
                word=clean_string(word);
                words[word]++;
            }
        }
        in_file.close();
        display(words);
}

void part2()
{
    std::map<std::string,std::set<int>>words;
    std::ifstream in_file("ThirstyCrow.txt");
    if(!in_file)
        std::cerr<<"Error opening the file"<<std::endl;
    std::string line{};
    std::string word{};
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
    display(words);
}


int main()
{
    part1();
    part2();
    return 0;
}
