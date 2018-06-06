#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>



int main(){
    std::vector<int> vi = {1,2,3,4,5,6,7,8,9};
    std::vector<int> v1,v3;
    std::list<int> v2;
    std::copy(vi.begin(),vi.end(),std::back_inserter(v1));
    for(const auto &i:v1)
        std::cout << i << " ";
    std::cout << std::endl;

    std::copy(vi.begin(),vi.end(),std::front_inserter(v2));
    for(const auto &i:v2)
        std::cout << i << " ";
    std::cout << std::endl;

    std::copy(vi.begin(),vi.end(),std::inserter(v3,v3.begin()));
    for(const auto &i:v3)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
