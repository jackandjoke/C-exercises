#include<vector>
#include<string>
#include<iostream>
#include<memory>
#include<initializer_list>
#include<stdexcept>
using namespace std;


class strBlob{
    
public:
    using size_type = vector<string>::size_type ; 

    strBlob():data(make_shared<vector<string>>()){}
    strBlob(const initializer_list<string> &il):data(make_shared<vector<string>>(il)){}

    size_type size() const{ return data -> size();}
    bool empty() const { return data -> empty();}

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

int main(){
    strBlob b1({"hello","world"});
    strBlob b2 = b1;
    b2.push_back("yeah");
    cout << b1.size() << endl;
    strBlob b3;
//    b3.back();
//    b3.front();
//    b3.pop_back();
    b1.pop_back();
    cout << b2.size() << endl;
     
    return 0;
}
