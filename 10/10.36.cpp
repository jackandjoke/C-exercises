#include<algorithm>
#include<iostream>
#include<list>



int main(){
    std::list<int> li={1,2,3,4,5,0,6};
    auto it = std::find(li.crbegin(),li.crend(),0);
    std::cout << std::distance(it,li.crend()) << std::endl;
}
