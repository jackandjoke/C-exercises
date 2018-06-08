#include<map>
#include<string>
#include<iostream>


using std::multimap;
using std::string;
using std::cin;
using std::cout;



int main(){
    multimap<string,string> mmp;
    mmp.insert({{"jac","play3"},{"jac","todo"}});
    mmp.insert({"b","c3"});
    mmp.insert({"a","j1"});
    mmp.insert({"a","b2"});
    mmp.insert({"b","c1"});

    for(const auto &item: mmp)
        cout << item.first << " " << item.second << std::endl;

    cout <<"==================" << std::endl;


    return 0;
}
