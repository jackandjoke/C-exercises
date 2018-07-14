#include<iostream>
#include<string>
#include<istream>
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
    while(cin){
        cout << "what we got is " << ps(cin);
        cout << endl;
    }
    return 0;
}


