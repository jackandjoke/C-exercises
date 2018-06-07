#include<map>
#include<iostream>
#include<string>
#include<vector>

using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cout;


int main(){
    map<string,vector<string>> families;
    families["tom"].push_back("jack tom");
    families["tom"].push_back("park tom");
    families["tuk"] = {};
    for(const auto &it : families){
        cout << it.first << " ";
        for(const auto &child: it.second)
            cout << child << std::endl;
    }
    return 0;
}
