#include<vector>
#include<iostream>
#include<exception>



int main(){
    std::vector<int> vect;
    try{
        int i1 = vect.at(0);
        std::cout << i1 << std::endl;
    }catch(std::exception &e){
        std::cout << "exception: " << e.what() << std::endl;
    }
    //int i2 = vect[0];
    //std::cout << i2 << std::endl;
    //int i3 = vect.front();
    //std::cout << i3 << std::endl;
    int i4 = *vect.begin();
    std::cout << i4 << std::endl;

    
    return 0;
}
