#include<iostream>




int main(){
    int x = 10;
    int copyx = x;
    auto decrease = [&x]()->bool{if( x == 0) return true; else { x -- ; return false;}};
    for(int i = 0; i < copyx + 5; i ++)
        std::cout << decrease() << std::endl;
    return 0;
}



