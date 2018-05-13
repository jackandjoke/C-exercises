#include<vector>
#include<string>
#include<iostream>


int main(){
    std::vector<char> vc = {'H','E','L','L','O'};
    std::string s (vc.begin(),vc.end());
    std::cout << s << std::endl;
    return 0;
}
