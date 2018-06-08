#include<map>
#include<iostream>


int main(){
    std::map<int,int> mp = {{0,1},{1,3},{2,5}};
    auto it = mp.begin();
    it->second = 5;
    for(const auto &it: mp){
        std::cout << it.first << " " << it.second << std::endl;
    }
    return 0;

}
