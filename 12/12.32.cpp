#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include<memory>
#include<sstream>
#include<memory>
#include<stdexcept>
#include<initializer_list>

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
    strBlobPtr(const strBlob &sb, int sz = 0):curr(sz),wptr(sb.data){}
    strBlobPtr & incr(){
        check(curr+1,"increment past end of strBlobPtr");
        curr++;
        return *this;
    }
    string & deref(){
        auto p = check(curr,"derefence past end");
        return (*p)[curr]; 
    }
    string deref(int i) const{
        auto p = check(i,"derefence past end");
        return (*p)[i];
    }

private:
    shared_ptr<vector<string>> check(size_t i, string msg) const;
    size_t curr;
    weak_ptr<vector<string>> wptr; 
};

shared_ptr<vector<string>> strBlobPtr::check(size_t i, string msg) const{
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











class QueryResult;

ostream& print(ostream &os, const QueryResult & qr);

class TextQuery{
public:
    TextQuery(ifstream &ifs);

    QueryResult query(const string &word) const;

private:
    strBlob data;
    map<string,shared_ptr<set<int>>> mp;
};


TextQuery::TextQuery(ifstream &ifs){
    string line;
    int line_num = 0;
    while(getline(ifs,line)){
        data.push_back(line);  
        istringstream is(line);
        string word;
        while(is >> word){
            if(mp.find(word) == mp.end()){
                mp[word] = make_shared<set<int>>();
            }
            mp[word] -> insert(line_num);
        }
        line_num++;
    }
}


class QueryResult{
    friend ostream & print(ostream &os, const QueryResult&);
public:
    QueryResult(const string &word, shared_ptr<set<int>> mpsp, const strBlob &sb)   
    {
        sought = word; 
        sp = mpsp;
        sbp = strBlobPtr(sb);
    }

private:
    string sought;
    shared_ptr<set<int>> sp; 
    strBlobPtr sbp;
};

void runQuery(ifstream &ifs){
    TextQuery tq(ifs);
    cout << "Please enter the word to search:\n";
    string word;
    while(1){
        if( ! (cin >> word) || word == "q")
            break;
        print(cout,tq.query(word)); 
    }
}
string make_plural(int i, string s){
    if(i > 1)   return s+"s";
    else return s;

}

ostream& print(ostream &os, const QueryResult & qr){
    cout << qr.sought << " appears " << qr.sp->size() <<" "<<  make_plural(qr.sp->size(),"time") <<endl; 
    for(const auto &v: (*qr.sp))
        cout << qr.sbp.deref(v) << endl;
    return os;
}
QueryResult TextQuery::query(const string &word) const{
    auto nodata = make_shared<set<int>>();
    auto loc = mp.find(word); 
    if(loc != mp.end()){
        return QueryResult(word,loc->second,data);
    }else
        return QueryResult(word,nodata,data);
    
}

int main(int argc, char *argvs[]){
    if(argc != 2){
        cerr << "Usage: ./12.30 <inputfile>\n";
        return 1;
    }
    ifstream ifs(argvs[1]);
    if(!ifs){
        cerr << "Failed to open " << argvs[1] << endl;
        return 1;
    }
    runQuery(ifs);
    return 0;
}

