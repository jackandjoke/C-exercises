#include<iostream>
#include<string>

using namespace std;


class HasPtr{
public:
    HasPtr(const string &s = string()) : ps(new string(s)),i(0){}
    HasPtr(const HasPtr &hpt){
        ps = new string(*hpt.ps);
        i = hpt.i;
    }
    void print(){
        cout << *ps << endl;
    }
private:
    string *ps;
    int i;
};


int main(){
    HasPtr p1("world");
    HasPtr p2 = p1;
    p2.print();
    return 0;
}
