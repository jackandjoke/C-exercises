#include<list>
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>

int main(){
    std::vector<int> vec;std::list<int> lst; int i;
    while(std::cin >> i)
        lst.push_back(i);
    std::copy(lst.cbegin(),lst.cend(),std::back_inserter(vec));
    for(const auto &c:vec)
        std::cout << c<<std::endl;
    std::vector<int> vec2;
    std::cout<<vec2.capacity()<<std::endl;
    //vec2.reserve(10);
    vec2.resize(10);
    std::cout<<vec2.capacity()<<std::endl;
    std::fill_n(vec2.begin(),10,0);
    std::cout<<vec2.capacity()<<std::endl;
    for(const auto &c:vec2)
        std::cout << c<<std::endl;

    return 0;
}
