#include<iostream>

using std::cout;

class funobj{

public:
    int operator() (int i, int j, int k){
        if(i) return j;
        else return k;
    }
};


int main(){
    funobj fo;
    cout << "fo(1,2,3) should return 2, return value is " << fo(1,2,3) << std::endl;
    cout << "fo(0,2,3) should return 3, return value is " << fo(0,2,3) << std::endl;
    return 0;
}
