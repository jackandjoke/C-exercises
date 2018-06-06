#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>



int main(){
    std::list<int> l;
    std::vector<int> vi = {1,2,2,3,4,4,5,6,6,7};
    std::unique_copy(vi.cbegin(),vi.cend(),std::back_inserter(l));
    for(const auto &i : l)
        std::cout << i << std::endl;
    return 0;
}
