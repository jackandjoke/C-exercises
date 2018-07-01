#include<iostream>
#include<string>


using namespace std;

class HasPtr{
    int val;
    string *ptr;
    int* use;
    friend void swap(HasPtr &, HasPtr&);
public:
    HasPtr():val(0),ptr(new string()),use(new int(1)){}
    HasPtr(const int &v, string *const s):val(v),ptr(new string(*s)),use(new int(1)){}

    HasPtr( HasPtr &rhs){
        (*rhs.use) ++;
        val = rhs.val;
        use = rhs.use;
        ptr = rhs.ptr;
    }

    HasPtr& operator=( HasPtr &rhs){
        (*rhs.use)++;
        if(--*use==0){
            delete ptr;
            delete use;
        }
        use = rhs.use;
        val = rhs.val;
        ptr = rhs.ptr;

        return *this;
    }
    void print(){
        cout << val << " " << *ptr << " "<< *use <<endl;
    }
    ~HasPtr(){
        if(--*use == 0) 
            delete ptr;
    }
};

void swap(HasPtr &lhs, HasPtr &rhs){
    cout <<"swaping\n";
    swap(lhs.ptr,rhs.ptr);
    swap(lhs.val,rhs.val);
}


int main(){
    string s1="hello";
    string s2="world";

    HasPtr h1(1,&s1);
    h1.print();
    HasPtr h2 = h1;
    h2.print();
    h1.print();

    HasPtr h3(2,&s2);
    HasPtr h4(h3);
    h3.print();
    h4.print();
    swap(h3,h1);
    h1.print();
    h3.print();


    return 0;
}
