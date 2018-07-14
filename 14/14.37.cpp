#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class IsEqual{

public:
    IsEqual (int i): v(i){}
    bool operator () (int rhs) {return v == rhs;}
private:
    int v;
};



int main(){
    vector<int> vi = {1,2,3,2,5,6,7,2};
    for(const auto &v: vi)
        cout << v<< " ";
    cout <<endl;

    replace_if(vi.begin(),vi.end(),IsEqual(2),0); 

    for(const auto &v: vi)
        cout << v<< " ";
    cout << endl;
    

    return 0;
}
