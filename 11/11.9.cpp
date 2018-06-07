#include<map>
#include<list>
#include<string>
#include<iostream>

using std::map;
using std::list;
using std::string;
using std::cin;
using std::cout;


int main(){
    map<string,list<int>> mp = {{"hello",{1,3,5}},{"world",{2}}};
    for(const auto &it: mp){
        cout << it.first << " ";
        for(const auto &l : it.second){
            cout << l << " ";
        }
        cout << std::endl;

    }
    return 0;
}
