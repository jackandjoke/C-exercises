#include<iostream>
#include<string>
#include<istream>
#include<vector>
using namespace std;

class PrintString{

public:
    string operator () (istream &is){
        string ret;
        getline(is, ret);
        return is? ret: string();
    }

};

int main(){
    PrintString ps;
    vector<string> vs;
    while(cin){
        string line =ps(cin);
        if(cin)
            vs.push_back(line);
    }
    for(const auto &l : vs)
        cout << l << endl;
    return 0;
}


