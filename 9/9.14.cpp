#include<list>
#include<vector>
#include<string>
#include<iostream>


int main(){
    char a1[]={'a','k','b'},a2[]={'u','j'};
    char *b1 =a1, *b2 =a2;
    std::list<char *> l = {b1,b2};
    std::vector<std::string> vect;
    vect.assign(l.begin(),l.end());
    for(const auto &c: vect)
        std::cout << c  << " ";
    std::cout << std::endl;
    return 0;
}
