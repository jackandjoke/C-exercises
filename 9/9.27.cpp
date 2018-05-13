#include<forward_list>
#include<iostream>





int main(){
    std::forward_list<int> fl = {1,2,3,4,5,6,7,8,9};

    auto prev = fl.before_begin();
    auto curr = fl.begin();
    while(curr != fl.end()){
        if(*curr % 2){
            curr = fl.erase_after(prev);
        }else{
            prev = curr;
            curr ++;
        }
    }
    for(const auto &ele : fl)
        std::cout << ele << " ";
    std::cout << std::endl;


    return 0;
}



