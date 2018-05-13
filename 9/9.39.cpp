#include<vector>
#include<iostream>

int  main(){
    std::vector<int> v;
    v.reserve(4);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.resize(v.size() + v.size() /2);
    std::cout << v.size() << " " << v.capacity() << std::endl;
    return 0;
}
