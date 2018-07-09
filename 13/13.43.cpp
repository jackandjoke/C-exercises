#include<iostream>
#include<string>
#include<memory>
#include<utility>
#include<initializer_list>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;
using std::allocator;
using std::pair;
using std::initializer_list;
using std::for_each;

class StrVec{
    static size_t ms;
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec &);
    StrVec(const initializer_list<string> &);
    ~StrVec();

    size_t size() const { return first_free - elements;}
    size_t capacity() const { return cap - elements;}
    string* begin() const { return elements;} 
    string* end() const {return first_free;}
    void push_back(const string &);

    StrVec & operator = (const StrVec&);
    void reserve(size_t n);
    void resize(size_t n, const string &val);

private:
    allocator<string> alloc;
    string *elements, *first_free, *cap;
    int alloc_n(int n);
    pair<string*,string*> alloc_n_copy(const string*,const string*);
    void check_n_alloc(){if(size() == capacity()) reallocate();}
    void reallocate();
    void free();
};

size_t StrVec::ms = 1;


StrVec::StrVec(const initializer_list<string> &ls){
    /*
    reserve(ls.size()); 
    for(const auto &v: ls)
        push_back(v);
    */
    auto data = alloc_n_copy(ls.begin(),ls.end());
    elements = data.first;
    first_free = cap = data.second;

}

void StrVec::reserve(size_t n){

    while(n > capacity()){ 
        reallocate();
    }
}

void StrVec::resize(size_t n, const string &val = string("")){
    if(n < size()){
        while( n < size()){
            alloc.destroy(--first_free);
        }
    }else if(n > size()){
        while(n > capacity()) reallocate();
        while(n > size()){
            alloc.construct(first_free++,val);
        }
    }
}


void StrVec::reallocate(){
    size_t new_capacity = capacity() == 0? 1: capacity() * 2;
    auto p = alloc.allocate(new_capacity);
    auto dest = p;
    auto q = elements;
    for(int i = 0; i < size(); i++){
        alloc.construct(dest++, std::move(*q++));
    }
    free();
    elements = p;
    first_free = dest;
    cap = elements + new_capacity;

}

void StrVec::free(){
    if(elements){
        auto st = elements;
        for_each(st,first_free,[&](string cur){alloc.destroy(&cur);});

        alloc.deallocate(elements,cap - elements);
    }
}
pair<string*,string*> StrVec::alloc_n_copy(const string *s1, const string *s2){
    auto be = alloc.allocate(s2-s1);
    return {be, uninitialized_copy(s1,s2,be)};

}

void StrVec::push_back(const string &s){
    check_n_alloc();
    alloc.construct(first_free++,s);
}
StrVec::StrVec(const StrVec &rhs){
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    elements = data.first;
    first_free = cap = data.second;
}
StrVec& StrVec::operator=(const StrVec& rhs){
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::~StrVec(){free();}

void print_size_cap(const StrVec &s){
    cout << "size: " << s.size() << " capacity: " << s.capacity() << endl;
}

int main(){
    StrVec s;
    //test push_back, size, capacity
    print_size_cap(s);
    s.push_back("h");
    print_size_cap(s);
    s.push_back("e");
    print_size_cap(s);
    s.push_back("l");
    print_size_cap(s);
    s.push_back("l");
    print_size_cap(s);
    s.push_back("o");
    print_size_cap(s);

    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it <<":";
    cout <<endl;
    //test resize

    s.resize(10);
    print_size_cap(s);
    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it <<":";
    cout << endl;

    s.resize(16,"bom");
    print_size_cap(s);
    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it <<":";
    cout << endl;

    s.resize(2);
    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it<<":" ;
    cout <<endl;
    print_size_cap(s);
    s.push_back("jack");
    print_size_cap(s);

    StrVec s2;
    print_size_cap(s2);
    s2.reserve(20);
    print_size_cap(s2);
    s2 = s;
    print_size_cap(s2);
    print_size_cap(s2);
    
    StrVec s3 = {"jack","makr","tom"};
    print_size_cap(s3);
    for(auto it = s3.begin(); it != s3.end(); it++)
        cout << *it<<":" ;
    cout <<endl;

    return 0;
}
