#include<iostream>
#include<map>
#include<set>
#include<iomanip>
#include<algorithm>
#include<fstream>
#include<sstream>

void display(std::map<std::string,int>m)
{
    std::cout<<std::setw(17)<<std::left()<<"WORD"
                 <<std::setw(27)<<std::right()<<"COUNT"<<std::endl;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    
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
            std::stringstream word;
            while(line>>word){
                word=clean_string(word);
                words[word]++;
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
