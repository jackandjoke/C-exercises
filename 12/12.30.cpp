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

ostream& print(ostream &os, const QueryResult & qr);

class TextQuery{
public:
    TextQuery(ifstream &ifs);

    QueryResult query(const string &word) const;

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
    friend ostream & print(ostream &os, const QueryResult&);
public:
    QueryResult(const string &word, shared_ptr<set<int>> mpsp, shared_ptr<vector<string>> spv)   
    {
        sought = word; 
        sp = mpsp;
        data = spv;
    }

private:
    string sought;
    shared_ptr<set<int>> sp; 
    shared_ptr<vector<string>> data;
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
        cout << (*qr.data)[v] << endl;
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

