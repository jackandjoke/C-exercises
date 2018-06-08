#include<map>
#include<iostream>
#include<typeinfo>
#include<unordered_map>



int main(){
    std::unordered_map<int,int> mp = {{5,0},{6,1},{7,2}};
    mp[5] = 3;
    mp.at(7) = 4;
    auto it = mp.begin();
    it->second ++;
    for(const auto &v:mp)
        std::cout << v.first << " " << v.second << std::endl;

    std::cout << typeid((mp[5])).name() << std::endl;
    return 0;
}
