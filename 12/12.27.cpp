#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include<memory>
#include<sstream>

using namespace std;


class QueryResult;

class TextQuery{
public:
    friend class QueryResult;
    TextQuery(ifstream &ifs);

    shared_ptr<set<int>> query(const string &word){
        if(mp.find(word) != mp.end())
            return mp[word];
        else return nullptr;
    }


private:
    shared_ptr<vector<string>> data;
    map<string,shared_ptr<set<int>>> mp;
};


TextQuery::TextQuery(ifstream &ifs){
    data = make_shared<vector<string>>();
    string line;
    int line_num = 0;
    while(getline(ifs,line)){
        data->push_back(line);  
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
public:
    QueryResult(){}
    void print(ostream &, shared_ptr<set<int>>);
    void runQuery(ifstream&);

private:
    shared_ptr<set<int>> sp; 
    shared_ptr<vector<string>> data;
};

void QueryResult::runQuery(ifstream &ifs){
    TextQuery tq(ifs);
    data = tq.data;
    cout << "Please enter the word to search:\n";
    string word;
    while(1){
        if( ! (cin >> word) || word == "q")
            break;
        print(cout,tq.query(word)); 
    }
}

void QueryResult::print(ostream &os, shared_ptr<set<int>> ssp){
    if(ssp == nullptr) {
        os << "appears 0 times\n";
        return ;
    }
    sp = ssp;
    for(const auto &v: *sp){
        os << (*data)[v] << endl;
    }
}

int main(){
    QueryResult qr;
    ifstream ifs("12.27.cpp");
    qr.runQuery(ifs);

    return 0;
}

