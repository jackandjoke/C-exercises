#include<map>
#include<string>
#include<iostream>


using std::multimap;
using std::string;
using std::cin;
using std::cout;


int main(){
    multimap<string,string> mmp;
    mmp.insert({"tom","play1"});
    mmp.insert({"tom","play2"});
    mmp.insert({"tom","play3"});
    mmp.insert({{"jac","play3"},{"jac","todo"}});

    for(const auto &item: mmp)
        cout << item.first << " " << item.second << std::endl;

    cout <<"==================" << std::endl;

    auto entries = mmp.count("jac");
    auto it = mmp.find("jac");
    while(entries){
        it = mmp.erase(it);
        entries--;
    }
    for(const auto &item: mmp)
        cout << item.first << " " << item.second << std::endl;
    return 0;
}
