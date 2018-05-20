#include<vector>
#include<algorithm>
#include<iostream>


int main(){
    std::vector<int> vec = {1,2,4,2,3,4,6,4,5,6,8,6,7,8,8};
    for(const auto &n : vec)
        std::cout<< n << " ";
    std::cout << std::endl;
    std::sort(vec.begin(),vec.end());

    auto it = std::unique(vec.begin(),vec.end());
    for(const auto &n : vec)
        std::cout<< n << " ";
    std::cout << std::endl;

    vec.erase(it,vec.end());
    for(const auto &n : vec)
        std::cout<< n << " ";
    std::cout << std::endl;

    return 0;
}
