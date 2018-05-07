#include<istream>
#include<iostream>
#include<string>



std::istream & read( std::istream &is){
    std::string data;
    while(!is.eof()){
        is >> data;
        std::cout << data << "\n";
        if(is.eof()) break;
    }
    is.clear();
    return is;
    /*while(is >> data){
     *
     *  std::cout << data;
     *}
     *
     */
}


int main(){
    read(std::cin);
    return 0;
}
