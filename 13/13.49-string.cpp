#include<iostream>
#include<vector>
#include<memory>
#include<utility>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::allocator;
using std::pair;
using std::for_each;
using std::uninitialized_copy;

class SimStr{

public:
    SimStr():elements(nullptr),first_free(nullptr),cap(nullptr){}
    SimStr(const char*);
    SimStr(const SimStr &);
    SimStr(SimStr &&) noexcept;
    ~SimStr();

    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}

    char* begin() const {return elements;}
    char* end() const {return first_free;}

    void reserve();
    void resize();

    void push_back(const char &c);

    SimStr& operator= (const SimStr &);
    SimStr& operator= (SimStr &&) noexcept;

private:
    allocator<char> alloc; 
    void free();
    void check_n_alloc();
    void reallocate(int);
    pair<char*,char*> alloc_n_copy(const char*, const char*);
    char* elements;
    char* first_free;
    char* cap;

};

SimStr::SimStr(SimStr &&rhs) noexcept: elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap){   
    cout <<  "in move constructor\n";
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

SimStr& SimStr::operator=(SimStr && rhs) noexcept{
    cout << "in move assignment\n";
    if(&rhs != this){
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}


void SimStr::push_back(const char &c){
    check_n_alloc();
    alloc.construct(first_free++,c);
}

SimStr::~SimStr(){free();}

void SimStr::check_n_alloc(){
    if(size() == capacity())
        reallocate(2);
}

void SimStr::free(){
    for_each(elements,first_free,[&](char c){alloc.destroy(&c);});
    alloc.deallocate(elements, cap - elements);
}

pair<char*,char*> SimStr::alloc_n_copy(const char *start, const char *end){
    auto p = alloc.allocate(end-start);
    return {p, uninitialized_copy(start,end,p)};
}

void SimStr::reallocate(int t){
    size_t new_capacity = (capacity() == 0 )? 1 : capacity() * t;

    auto new_p = alloc.allocate(new_capacity);
    auto dest = new_p;

    auto p = elements;
    while(p!=first_free){
        alloc.construct(dest++,*p);
        p++;
    }

    free();

    elements = new_p;
    first_free = dest;
    cap = elements + new_capacity;
}


SimStr::SimStr(const char *ca){
    const char *end = ca;
    while(*end !='\0')
        end++;
    auto data = alloc_n_copy(ca,end);
    elements = data.first;
    first_free = cap = data.second;
}
SimStr::SimStr(const SimStr& rhs){
    cout << "in copy constructor !\n";
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    elements = data.first;
    first_free = cap = data.second;
}

SimStr& SimStr::operator=(const SimStr &rhs){
    cout << "in operator = function !!!\n";
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void print_simstr(const SimStr &s){
    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it;
    cout <<endl;
    cout << "size(): " << s.size() << "  capacity(): " << s.capacity() << endl;
}

int main(){
    vector<SimStr> vs; 
    cout << vs.size() << " " << vs.capacity() << endl; 

    vs.push_back("hello");
    cout << vs.size() << " " << vs.capacity() << endl; 

    vs.push_back("world");
    cout << vs.size() << " " << vs.capacity() << endl; 

    vs.push_back("junk");
    cout << vs.size() << " " << vs.capacity() << endl; 

    vs.push_back("food");
    cout << vs.size() << " " << vs.capacity() << endl; 
    
    SimStr s2("jack");
    vs.push_back(s2);
    cout << vs.size() << " " << vs.capacity() << endl; 
    return 0;
}
