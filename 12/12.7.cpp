#include<vector>
#include<iostream>
#include<ostream>
#include<istream>
#include<memory>

using std::vector;
using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::shared_ptr;
using std::make_shared;

using Sptr = shared_ptr<vector<int>>;

void write2vec(istream &is, Sptr sp){
    int tmp;
    while( is >> tmp ) (*sp).push_back(tmp);
}
void print(ostream &os, Sptr sp){
    for(const auto &v : *sp)
        os << v << " ";
    os << std::endl;
}


int main(){
//    auto sp = make_shared<vector<int>>();
    shared_ptr<vector<int>> sp(new vector<int>());
    write2vec(cin,sp);
    print(cout,sp);

    return 0;
}

