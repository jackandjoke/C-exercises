#include<iostream>
#include<vector>
#include<list>


int main(){
    std::list<int> l={1,2,3,4,5};
    std::vector<int> v={2,42,50};
    std::vector<double> vect1(l.begin(),l.end());
    for(const auto & p: vect1)
        std::cout << p << " ";
    std::cout << std::endl;

    std::vector<double> vect2(v.begin(),v.end());
    for(const auto & p: vect2)
        std::cout << p << " ";
    std::cout << std::endl;
    return 0;
}
