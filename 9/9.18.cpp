#include<deque>
#include<string>
#include<iostream>

int main(){
    
    std::deque<std::string> dq;
    std::string str;
    while( std::cin >> str){
        dq.push_back(str);
    }
    for(const auto &s : dq)
        std::cout << s << std::endl;


    return 0;
}
