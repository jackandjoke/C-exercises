#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;



int main(int argc, char *argvs[]){
    if(argc != 2){
        cout << "Usage: ./12.28 <inputfile>\n";
        return 1;
    }
    ifstream ifs(argvs[1]);
    if(!ifs){
        cout << "Failed to open " << argvs[1] << endl;
        return 1;
    }
    string line;
    vector<string> vs;
    map<string,set<int>> mp;
    int line_num = 0;
    while(getline(ifs,line)){
        vs.push_back(line); 
        istringstream is(line);
        string word;
        while(is >> word){
            mp[word].insert(line_num);
        }
        line_num ++;
    }

    while(1){
        cout << "Please enter the word to search:\n";    
        string word;
        if( !(cin >> word) || word == "q" )
            break;

        if(mp.find(word)!=mp.end()){
            for(const auto &v: mp[word])
                cout << vs[v] << endl;
        }else{
            cout << word << " appears 0 time\n"; 
        }

    }


    return 0;
}
