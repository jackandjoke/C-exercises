#include<iostream>
#include<vector>
using namespace std;

struct X{
    X(){ cout << "X()\n";}
    X(const X&) {cout << "X(const X&)\n";}
    X& operator = (const X& rhs){
        cout << "operator =\n";
        return *this;
    }
    ~X(){cout << "~X()\n";}

};

void p(X x){
    cout << "p(X x)\n";
}
void p2(X &x){
    cout << "p(X &x)\n";
}



int main(){
    cout <<"x1 ... \n";
    X x1;
    cout <<"x1 finished ... \n";
    cout <<"x2 ... \n";
    X x2(x1);
    cout <<"x2 finished ... \n";
    cout <<"x3 ... \n";
    X x3 = x2;
    cout <<"x3 finished ... \n";
    
    p(x3);
    p2(x1);
    X* xp = new X();
    X* xp2 = new X(*xp);
    vector<X> vx;
    vx.push_back(x1);
    vx.push_back(x3);
    vx.push_back(*xp);
    vector<X*> vxp;
    vxp.push_back(xp2);
    return 0;
};
