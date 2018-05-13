#include<vector>
#include<iostream>

void print_vect(const std::vector<int> &vect){
    for(const auto &p : vect)
        std::cout << p << " ";
    std::cout << std::endl;
}


int main(){
    
    std::vector<int> v1;

    std::vector<int> v2(v1);
    std::vector<int> v3 = v2;

    std::vector<int> v4 = {1,2};

    std::vector<int> v5(v4.begin(),v4.end());

    std::vector<int> v6(5,2);

    std::vector<int> v7(10);

    print_vect(v1);
    print_vect(v2);
    print_vect(v3);
    print_vect(v4);
    print_vect(v5);
    print_vect(v6);
    print_vect(v7);


    return 0;
}
