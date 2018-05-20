#include<iostream>
#include<algorithm>
#include<iterator>

int main(){
    int a[] = {1,2,3,4,5,23,4,5,67,10};
    std::fill_n(std::begin(a),sizeof(a)/sizeof(*a),0);
    for(int i = 0; i < sizeof(a)/sizeof(*a) ; i ++)
        std::cout << a[i] << " ";
    std::cout << std::endl;


    return 0;
}
