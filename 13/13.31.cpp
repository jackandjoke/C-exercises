#include<iostream>
#include<string>
#include<algorithm>


using std::string;
using std::vector;
using std::sort;
using std::cout;
using std::endl;

class HasPtr{
    int val;
    string *ptr;
    friend void swap(HasPtr &, HasPtr&);
public:
    HasPtr():val(0),ptr(new string()){}
    HasPtr(const int &v, string *const s):val(v),ptr(new string(*s)){}

    HasPtr( const HasPtr &rhs){
        val = rhs.val;
        ptr = new string(*rhs.ptr);
    }

    HasPtr& operator=( const HasPtr &rhs){
        val = rhs.val;
        auto tmp = new string(*rhs.ptr);
        delete ptr;
        ptr = tmp;

        return *this;
    }
    void print(){
        cout << val << " " << *ptr << " "<<endl;
    }
    ~HasPtr(){
        delete ptr;
    }
    bool operator< ( const HasPtr &rhs){
        return val < rhs.val;
    }
};

void swap(HasPtr &lhs, HasPtr &rhs){
    using std::swap;
    cout <<"swaping "<< lhs.val << " and " << rhs.val << "\n";
    swap(lhs.ptr,rhs.ptr);
    swap(lhs.val,rhs.val);
}


int main(){
    vector<HasPtr> vh;
    string s = "hold";
    for(int i = 100 ; i >= 0; i--)
        vh.push_back(HasPtr(i,&s));
    sort(vh.begin(),vh.end());


    return 0;
}
