#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Smaller{
    bool operator () (const string &lhs, const string &rhs) { return lhs < rhs;}
};

struct SmallerSize{
    bool operator () (const string &lhs, const string &rhs) { return lhs.size() < rhs.size();}
};

void elimDups(vector<string> &words){
    stable_sort(words.begin(),words.end(),Smaller());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}

class CheckLen{
public:
    CheckLen(int ml = 10): min_len(ml) {}
    bool operator()(const string &s) const{ return s.size() >= min_len;}

private:
    int min_len;
};

void bigges(vector<string> &words, size_t sz){
    elimDups(words); 
    stable_sort(words.begin(),words.end(),SmallerSize());
    auto wc = find_if(words.begin(),words.end(),CheckLen(sz));
    
    while(wc != words.end()){
        cout << *wc << "\n";
        wc ++;
    }
}


int main(){
    vector<string> vs = {"hhh","wwww","hhh","wwww","apple","is","pear","is"};
    bigges(vs,2);
    return 0;
}
