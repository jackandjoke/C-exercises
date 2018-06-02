#include<iostream>
#include<algorithm>
#include<vector>
#include<string>




int main(){
    std::vector<std::string> words = {"How","many","666666","words","in","helloo","monday"};
    std::cout << std::count_if(words.begin(),words.end(),[](const std::string &s1){return s1.size() >= 6; });
    std::cout<<std::endl;
    return 0;
}   
