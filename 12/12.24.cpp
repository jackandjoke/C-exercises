#include<iostream>
#include<string>


using namespace std;

const int LEN = 5;


int main(){
    string str;
    char *ca = new char[LEN];
    cin >> str;
    if(str.size() > LEN){
        delete []ca;
        ca = new char[str.size()+1];
    }
    for(int i = 0; i < str.size();i++)
        ca[i] = str[i];

    cout << ca ;
    delete []ca;

    return 0;
}
