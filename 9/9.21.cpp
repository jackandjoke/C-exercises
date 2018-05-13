#include<vector>
#include<iostream>
#include<string>



int main(){
    std::vector<std::string> vect;
    std::string str;
    std::vector<std::string>::iterator iter = vect.begin();
    while(std::cin >> str){
        iter = vect.insert(iter,str);
    }
    for(const auto &s: vect)
        std::cout << s << " ";
    std::cout << std::endl;
    return 0;
}
