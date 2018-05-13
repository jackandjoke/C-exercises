#include<list>
#include<iostream>



int main(){
    std::list<int> l = {0,1,2,3,4,5,6,7,8,9};
    auto it = l.begin();
    while(it != l.end()){
        if(*it % 2){
            it = l.insert(it, *it);
            it ++;
            it ++;
        }else{
            it = l.erase(it);
        }
    }
    for(const auto &ele : l)
        std::cout << ele << " ";
    std::cout << std::endl;
    return 0;
}
