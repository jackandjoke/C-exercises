#include<vector>
#include<cassert>
#include<iostream>

bool find(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int target){
    assert(begin <= end);
    while(begin != end){
        if(*begin == target ) return true;
        begin ++;
    }
    return false;

}

int main(){
    std::vector<int> vect {1,2,9,20,123,35};
    std::cout << find(vect.begin(),vect.end(),20) << std::endl;
    std::cout << find(vect.begin(),vect.end(),1) << std::endl;
    std::cout << find(vect.begin(),vect.end(),35) << std::endl;
    std::cout << find(vect.begin(),vect.end(),213) << std::endl;
    return 0;
}
