#include<vector>
#include<iostream>



int main(){
    std::vector<int> vect = {1,2,3,4};
    vect.erase(vect.end(),vect.end());
    for(const auto &ele : vect)
        std::cout << ele << std::endl;
    return 0;
}
