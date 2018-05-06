#include<istream>
#include<iostream>
#include<string>



std::istream & read( std::istream &is){
    std::string data;
    while(!is.eof()){
        is >> data;
        if(is.eof()) break;
        std::cout << data << "\n";
    }
    is.clear();
    return is;
}
