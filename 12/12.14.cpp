#include<iostream>
#include<memory>
#include<string>
#include<stdexcept>


using std::cin;
using std::cout;
using std::shared_ptr;
using std::string;
using std::out_of_range;

struct destination{
    string name;
    destination(string s):name(s){}
};

struct connection{
    string from;
    string to;
};

struct connection connect(struct destination *d){
    cout << "connect " << "to " << d -> name << std::endl;
    connection c;
    c.from = "origin";
    c.to = d->name;
    return c;
}

void disconnect(struct connection* c){
    cout << "disconnect from " << c->from  << "to " << c->to << std::endl;
}
void end_connection(struct connection* c){
    disconnect(c);
}

void f(struct destination *d){
    struct connection c = connect(d);
    shared_ptr<struct connection> p(&c,end_connection);
    throw 20;

}


int main(){
    struct destination d("8.8.8.8");
    f(&d);

    return 0;
}

