#include<map>
#include<iostream>
#include<string>
#include<vector>

using std::multimap;
using std::vector;
using std::string;
using std::cin;
using std::cout;


int main(){
    multimap<string,vector<string>> families;
    //families["tom"].push_back("jack tom");
    //families["tom"].push_back("park tom");
    families.insert({"tom",{"new","bro","tk"}});
    families.insert({"tom",{"new2","no"}});
    //families["tuk"] = {};
    for(const auto &it : families){
        cout << it.first << " ";
        for(const auto &child: it.second)
            cout << child << " ";
        cout << std::endl;
    }
    return 0;
}
