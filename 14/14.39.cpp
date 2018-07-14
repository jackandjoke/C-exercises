#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;


class CheckLen{
public:
    CheckLen(int ml = 10): min_len(ml) {}
    bool operator()(const string &s) const{ return s.size() >= min_len;}

private:
    int min_len;
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

    CheckLen cl(10);

    string word;
    int ans[2] = {0};
    while(ifs >> word){
        if(cl(word))
            ans[1]++;
        else
            ans[0]++;
    }
    cout << ans[0] << " words are shorter than 10\n";
    cout << ans[1] << " words are longer than 10\n";

}
