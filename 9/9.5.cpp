#include<vector>
#include<cassert>
#include<iostream>

std::vector<int>::const_iterator myfind(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int target){
    assert(begin <= end);
    while(begin != end){
        if(*begin == target ) break;
        begin ++;
    }
    return begin;
}

int main(){
    std::vector<int> vect {1,2,9,20,123,35};
    std::vector<int>::const_iterator it1,it2,it3,it4;
    it1 = myfind(vect.begin(),vect.end(),20);
    it2 = myfind(vect.begin(),vect.end(),1);
    it3 = myfind(vect.begin(),vect.end(),35);
    it4 = myfind(vect.begin(),vect.end(),234);
    std::cout << *it1 << std::endl;
    std::cout << *it2 << std::endl;
    std::cout << *it3 << std::endl;
    if(it4 == vect.end())
        std::cout<<"not found" << std::endl;
    return 0;
}
