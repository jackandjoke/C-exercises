#include<vector>
#include<iostream>
#include<ostream>
#include<istream>

using std::vector;
using std::cin;
using std::cout;
using std::istream;
using std::ostream;

void write2vec(istream &is, vector<int> *vp){
    int tmp;
    while( is >> tmp ) (*vp).push_back(tmp);
}
void print(ostream &os, vector<int> *vp){
    for(const auto &v : *vp)
        os << v << " ";
    os << std::endl;
}


int main(){
    vector<int> * vp = new vector<int> {};
    write2vec(cin,vp);
    print(cout,vp);
    delete vp;

    return 0;
}

