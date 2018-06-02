#include<iostream>



int mysum(int rhs){
    int lhs = 1000; 
    auto f = [lhs](int r){return lhs + r;};
    return f(rhs);
}


int main(){

    std::cout << mysum(520) << std::endl;
    return 0;
}





