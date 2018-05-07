#include<fstream>
#include<ostream>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include<cassert>


std::vector<std::string> read(std::istream &is){
    std::string line;
    std::vector<std::string> lines;
    while(is){
        getline(is,line);
        lines.push_back(line);
    }
    return lines;
}


int main(int argc, char *argv[]){
    std::vector<std::string> lines;
    std::ifstream ifs(argv[1]);
    assert(ifs);
    lines = read(ifs);
    for(auto l : lines){
        std::istringstream iss(l);
        while(iss){
            std::string word;
            iss >> word;
            std::cout << word << std::endl;
        }
    }


    return 0;
}
