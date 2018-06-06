#include<algorithm>
#include<iostream>
#include<vector>
#include<list>


int main(){
    std::vector<int> vi = {1,2,3,4,5,6,7,8,9,0};
    std::list<int> li;
    std::copy(vi.rbegin()+3,vi.rbegin()+8,std::back_inserter(li));
    for(const auto &i: li)
        std::cout <<i << " ";
    std::cout << std::endl;
    return 0;
}
