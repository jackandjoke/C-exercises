#include<string>
#include<iostream>
#include<utility>
#include<vector>

using std::string;
using std::cin;
using std::cout;
using std::pair;
using std::vector;


int main(){

    string str;
    int val;
    vector<pair<string,int>> vp;
    while(cin >> str && cin >> val){
        vp.push_back(std::make_pair(str,val)); 
        vp.push_back(pair<string,int>(str,val)); 
        vp.push_back({str,val});
        vp.emplace_back(str,val);

    }
    for(const auto &p : vp){
        cout << p.first << " " << p.second << std::endl;
    }


}
