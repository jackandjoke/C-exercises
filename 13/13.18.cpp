#include<iostream>
#include<string>

using namespace std;


class Employee{
    static int cur_uid;
    string name;
    int uid;
public:
    Employee():name(""),uid(cur_uid++){}
    Employee(const string &s):name(s),uid(cur_uid++){}

    void print(){
        cout << name <<" " << uid << endl;
    }
};


int Employee::cur_uid = 0;

int main(){
    Employee e1;
    e1.print();
    for(int i = 0; i < 10; i++){
        Employee e( string(1,'a'+i) );
        e.print();
    }
    return 0;
}
