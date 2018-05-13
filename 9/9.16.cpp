#include<vector>
#include<list>
#include<iostream>

bool is_equal(const std::vector<int> &lhs, const std::list<int> &rhs){
    if(lhs.size() != rhs.size()) return false;

    std::vector<int>::const_iterator it1 = lhs.cbegin();
    std::list<int>::const_iterator it2 = rhs.cbegin();
    while(it1 != lhs.end()){
        if(*it1 != *it2) return false; 
        it1 ++;
        it2 ++;
    }
    return true;
}

int main(){
    std::vector<int> v1 = {1,3,5,7,9,12};
    std::list<int> v2 = {1,3,9};
    std::list<int> v4 = {1,3,5,7,9,12};

    std::cout << is_equal(v1,v2) << std::endl;
    std::cout << is_equal(v1,v4) << std::endl;
    
    return 0;
}
