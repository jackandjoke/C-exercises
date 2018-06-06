#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>



int main(){
    std::vector<int> vi = {1,2,3,4,5,6,7,8,9};
    std::copy(vi.crbegin(),vi.crend(),std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;

    std::copy(vi.cbegin(),vi.cend(),std::ostream_iterator<int>(std::cout," "));

    return 0;
}
