#include<vector>
#include<list>
#include<iostream>
#include<iterator>

void my_delete(std::vector<int> &vect, std::list<int> &l){
    auto it = vect.begin();
    while(it != vect.end()){
        if(*it % 2)
            it ++;
        else
            it = vect.erase(it);
    }
    auto it2 = l.begin();
    while(it2 != l.end()){
        if(*it2 % 2)
            it2 = l.erase(it2);
        else
            it2 ++;
    }

}

int main(){
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    std::vector<int> vect(std::begin(ia),std::end(ia));
    std::list<int> l(std::begin(ia),std::end(ia));
    my_delete(vect,l);
    for(const auto &ele: vect)
        std::cout << ele <<" ";
    std::cout << std::endl;
    for(const auto &ele: l)
        std::cout << ele <<" ";
    std::cout << std::endl;
    return 0;
}
