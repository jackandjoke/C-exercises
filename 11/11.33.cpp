#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<cassert>
#include<sstream>

using std::cout;
using std::ifstream;
using std::unordered_map;
using std::string;
using std::istringstream;
using std::getline;

unordered_map<string,string> build_map(ifstream &rules){
    unordered_map<string,string> words_map;
    string key, value; 
    while(rules >> key && getline(rules, value)){
        if(value.size() > 1)
            words_map[key] = value.substr(1);
    }
    return words_map;

}

const string& transform(const unordered_map<string,string> &words_map, const string &key){

    auto it = words_map.find(key);
    if(it == words_map.end())
        return key;
    else return it->second;

}

void words_transform(ifstream &rules, ifstream &input){
    auto words_map = build_map(rules);
    string line;
    while(getline(input,line)){
        istringstream line_str(line);
        string w;
        int first_word = 1;
        while(line_str >> w){
            if(!first_word)
                cout << " ";
            else
                first_word = !first_word;

            cout << transform(words_map, w);
        }
        cout << std::endl;
    }
    
}


int main(int argc, char *argv[]){
    assert(argc == 3);
    ifstream rules(argv[1]);
    ifstream input(argv[2]);
    words_transform(rules, input);
    return 0;
}
