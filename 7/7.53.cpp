#include<iostream>

class Debug{
public:
    constexpr Debug(bool b = true):io(b),hw(b),other(b) {}
    constexpr Debug(bool b, bool c, bool d): io(b),hw(c),other(d){}
    constexpr bool any(){return io | hw | other;}

    void set_io(bool b) {io=b;}
    void set_hw(bool b) {hw=b;}
    void set_other(bool b){other=b;}

private:
    int io;
    int hw;
    int other;
};


int main(){
    Debug dg(true);
    std::cout << dg.any()<<std::endl;
    return 0;
}
