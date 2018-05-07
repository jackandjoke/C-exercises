#include<istream>
#include<iostream>
#include<string>
#include<sstream>



std::istream & read( std::istream &is){
    std::string data;
    while(!is.eof()){
        is >> data;
        std::cout << data << "\n";
        if(is.eof()) break;
    }
    is.clear();
    return is;
}


int main(){
    std::stringstream s("Hello World, your majesty!"); 
    read(s);
    return 0;
}
