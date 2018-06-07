#include<iostream>
#include<list>
#include<algorithm>

void elimDups(std::list<int> &li){
    li.sort();
    li.unique();
}


int main(){
    std::list<int> li = {1,3,5,7,9,8,8,9,2,2,3};
    elimDups(li);
    for(auto it = li.cbegin(); it != li.cend(); it ++)
        std::cout << *it << std::endl;


}
