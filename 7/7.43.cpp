#include<vector>
struct NoDefault{
    NoDefault(int i){}
};

struct C{
    NoDefault nf;
    C(): nf(0){}
};


int main(){
    C a;
    // illegal
    std::vector<C> vec(10);
    return 0;
}
