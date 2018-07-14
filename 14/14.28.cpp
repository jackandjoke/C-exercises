#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<memory>
#include<initializer_list>
#include<stdexcept>

using namespace std;

class strBlobPtr;


class strBlob{
    friend class strBlobPtr;
public:
    using size_type = vector<string>::size_type ; 

    strBlob():data(make_shared<vector<string>>()){}
    strBlob(const initializer_list<string> &il):data(make_shared<vector<string>>(il)){}

    size_type size() const{ return data -> size();}
    bool empty() const { return data -> empty();}
    strBlobPtr begin();
    strBlobPtr end() ;

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

class strBlobPtr{
public:
    strBlobPtr():curr(0){}
    strBlobPtr(strBlob &sb, int sz = 0):curr(sz),wptr(sb.data){}
    strBlobPtr & incr(){
        check(curr+1,"increment past end of strBlobPtr");
        curr++;
        return *this;
    }
    string & deref(){
        auto p = check(curr,"derefence past end");
        return (*p)[curr]; 
    }
    strBlobPtr& operator ++(){
        check(curr,"increment past end of strBlobPtr");
        curr ++;
        return *this;
    }
    strBlobPtr operator ++(int x){
        strBlobPtr ret = *this;
        ++*this;
        return ret;
    }

    strBlobPtr &operator --(){
        curr --;
        check(curr,"decrement past begin of strBlobPtr");
        return *this;
    }
    strBlobPtr operator --(int x ){
        strBlobPtr ret = *this;
        --*this;
        return ret;
    }

    strBlobPtr operator + (size_t n){
        check(curr+n,"increment past end of strBlobPtr");
        curr += n;
        return *this;
    }

    strBlobPtr operator - (size_t n){
        return *this + (-n);
    }


private:
    shared_ptr<vector<string>> check(size_t i, string msg);
    size_t curr;
    weak_ptr<vector<string>> wptr; 
};


shared_ptr<vector<string>> strBlobPtr::check(size_t i, string msg){
    auto p = wptr.lock();
    if(!p){
        throw runtime_error("unbound strBlobPtr");
    }
    if(i >= p->size() )
        throw out_of_range(msg);

    return p;

}
strBlobPtr strBlob::begin(){ return strBlobPtr(*this);}
strBlobPtr strBlob::end() { return strBlobPtr(*this, data->size());}



int main(int argc, const char *argvs[]){
    if(argc != 2){
        cerr <<"Usage: ./12.20 <inputfile>\n";
        return 1;
    }
    strBlob sb;
    ifstream ifs(argvs[1]);
    if(!ifs){
        cerr << "Unable to open file " << argvs[1] << endl;
        return 1;
    }
    string line;
    while(getline(ifs,line)){
        sb.push_back(line);
    }
    auto it = sb.begin();
    while(1){
        try{
            cout << it.deref() << endl;
            ++it;
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
