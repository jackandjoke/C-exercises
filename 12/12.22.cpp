#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<memory>
#include<initializer_list>
#include<stdexcept>

using namespace std;

class constStrBlobPtr;


class strBlob{
    friend class constStrBlobPtr;
public:
    using size_type = vector<string>::size_type ; 

    strBlob():data(make_shared<vector<string>>()){}
    strBlob(const initializer_list<string> &il):data(make_shared<vector<string>>(il)){}

    size_type size() const{ return data -> size();}
    bool empty() const { return data -> empty();}

    constStrBlobPtr begin() const;
    constStrBlobPtr end() const;

    void push_back(const string &s){ data->push_back(s);}
    void pop_back();

    string & back();
    string & front();

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg);

};

void strBlob::check(size_type i, const string &msg){
    if(i >= data->size()){
        throw out_of_range(msg);
    }
}

string & strBlob::back(){
    check(0,"back() from empty vector\n");
    return data->back();
}

string & strBlob::front(){
    check(0,"front() from empty vector\n");
    return data->front();
}

void strBlob::pop_back(){
    check(0,"pop_back() from empty vector\n");
    data->pop_back();
}

class constStrBlobPtr{
public:
    constStrBlobPtr():curr(0){}
    constStrBlobPtr(const strBlob &sb, int sz = 0):curr(sz),wptr(sb.data){}
    constStrBlobPtr & incr(){
        check(curr+1,"increment past end of strBlobPtr");
        curr++;
        return *this;
    }
    const string & deref(){
        auto p = check(curr,"derefence past end");
        return (*p)[curr]; 
    }

private:
    shared_ptr< vector<string>> check(size_t i, string msg);
    size_t curr;
    weak_ptr< vector<string>> wptr; 
};

shared_ptr<vector<string>> constStrBlobPtr::check(size_t i, string msg){
    auto p = wptr.lock();
    if(!p){
        throw runtime_error("unbound strBlobPtr");
    }
    if(i >= p->size() )
        throw out_of_range(msg);

    return p;

}
constStrBlobPtr strBlob::begin() const{ return constStrBlobPtr(*this);}
constStrBlobPtr strBlob::end() const { return constStrBlobPtr(*this, data->size());}



int main(int argc, const char *argvs[]){
    const strBlob sb={"hello","world","today"};
    auto it = sb.begin();
    while(1){
        try{
            cout << it.deref() << endl;
            it.incr();
        }catch(out_of_range ofr){
            //cout << ofr.what()<<endl;;
            break;
        }catch(runtime_error err){
            cout << err.what() << endl;
            break;
        }
    }

    return 0;
}
