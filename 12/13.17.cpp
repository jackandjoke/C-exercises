#include<iostream>

using namespace std;
struct numbered;
void f(const numbered &);
struct numbered{
public:
    friend void f(const numbered &s);
    numbered(int i = 0):mysn(i){}
    numbered(const numbered& n)  {mysn = n.mysn + 1;}
private:
        int mysn;
        
};
void f(const numbered &s){
    cout << s.mysn << endl;
}

int main(){
    numbered a(23), b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
