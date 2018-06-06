#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using std::placeholders::_1;

bool lessthan6(const std::string &s, std::string::size_type sz ){
    return s.size() <= sz;
}

int main(){
    int sz = 6;
    std::vector<std::string> words = {"sixsix","this","aaaaaaa","more","maybe","mondays"}; 
    std::cout << std::count_if(words.cbegin(),words.cend(),std::bind(lessthan6,_1,sz))<<std::endl;

    return 0;
}
