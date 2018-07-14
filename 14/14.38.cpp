#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;


class CheckLen{
public:
    CheckLen(int ml): max_len(ml) {}
    bool operator()(const string &s) const{ return s.size() == max_len;}

private:
    int max_len;
};


int main(int argc, char *argv[]){
    if(argc != 2){
        cout << "Usage: ./14.38 <inputfile>\n";
        return 1;
    }
    ifstream ifs; 
    ifs.open(argv[1]);
    if(!ifs){
        cout << "Cannot open file " << argv[1] << endl;
        return 1;
    }

    vector<CheckLen> vc;
    for(int i= 1; i <= 10; i++) 
        vc.push_back(CheckLen(i));

    string word;
    int ans[10] = {0 };
    while(ifs >> word){
        for(int i = 1; i <= 10; i++)
            if( vc[i-1](word) ){
                ans[i-1]++;
                break;
            }
    }
    for(int i = 0; i < 10; i++)
        cout << ans[i] << " words have len " << i+1 << endl;

}
