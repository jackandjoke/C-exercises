#include<iostream>
#include<string>


using namespace std;

class HasPtr{
    int val;
    string *ptr;
public:
    HasPtr():val(0),ptr(new string()){}
    HasPtr(const int &v, string *const s):val(v),ptr(new string(*s)){}

    HasPtr(const HasPtr &rhs){
        val = rhs.val;
        ptr = new string(*rhs.ptr);
    }

    HasPtr& operator=(const HasPtr &rhs){
        val = rhs.val;
        string *tmp = new string(*(rhs.ptr));
        if(ptr!=nullptr)
            delete ptr;
        ptr = tmp;
        return *this;
    }
    void print(){
        cout << val << " " << *ptr << endl;
    }
    void rc(){
        *ptr = *ptr + *ptr;
    }
    ~HasPtr(){delete ptr;}
};


int main(){
    string s1="hello";
    string s2="world";

    HasPtr h1(1,&s1);
    h1.print();
    HasPtr h2 = h1;
    h2.print();
    h2.rc();
    h2.print();
    h1.print();

    HasPtr h3(2,&s2);
    HasPtr h4(h3);
    h3.print();
    h4.print();
    h4.rc();
    h4.print();
    h3.print();


    return 0;
}
