#include<set>
#include<vector>
#include<iostream>
#include<string>


using std::set;
using std::vector;
using std::cin;
using std::cout;
using std::string;


int main(){
    string word;
    vector<string> vs;
    while(cin >> word){
        auto it = vs.begin();
        while(it!=vs.end()){
            if(*it == word)
                break;
            it++;
        }
        if(it==vs.end())
            vs.push_back(word);
    }
    for(const auto &w: vs)
        cout << w << " ";
    cout << std::endl;
    return 0;
}
