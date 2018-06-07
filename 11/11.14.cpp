#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<utility>

using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::pair;


int main(){
    map<string,vector<pair<string,string>>> families;
    families["tom"].emplace_back("jack tom","1995-12-3");
    families["tom"].emplace_back("park tom","1996-2-2");
    families["tuk"] = {};
    for(const auto &it : families){
        cout << it.first << " ";
        for(const auto &child: it.second)
            cout << child.first <<" " << child.second << std::endl;
    }
    return 0;
}
