#include<iostream>


int main(){
    auto f = [](int lhs, int rhs){return lhs+rhs;};
    auto f2 = [](int lhs, int rhs) -> int {return lhs+rhs;};
    std:: cout<< f(1,99) << std::endl;
    std:: cout<< f2(1,99) << std::endl;
    return 0;
}
