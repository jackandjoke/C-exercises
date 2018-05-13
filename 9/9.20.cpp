#include<list>
#include<deque>
#include<iostream>


void copy(std::list<int> &l, std::deque<int> &dq1, std::deque<int> &dq2){
    std::list<int>::const_iterator it = l.cbegin(); 
    int odd = 1;
    while(it != l.cend()){
        if(odd){
            dq1.push_back(*it);
        }else
            dq2.push_back(*it);
        it ++;
        odd = !odd;
    }
}

int main(){
    std::list<int> l = {1,2,3,4,5,6,7,8,9};
    std::deque<int> dq1,dq2;

    copy(l,dq1,dq2);

    for(const auto & c: dq1)
        std::cout << c << " ";
    std::cout << std::endl;

    for(const auto & c: dq2)
        std::cout << c << " ";
    std::cout << std::endl;
    return 0;
}
