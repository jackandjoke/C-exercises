#include<vector>
#include<iostream>


#include"13.48.h"


using std::vector;
using std::cout;
using std::endl;






int main(){
    vector<SimStr> vs; 
    cout << vs.size() << " " << vs.capacity() << endl; 

    vs.push_back("hello");
    cout << vs.size() << " " << vs.capacity() << endl; 

    vs.push_back("world");
    cout << vs.size() << " " << vs.capacity() << endl; 

    vs.push_back("junk");
    cout << vs.size() << " " << vs.capacity() << endl; 

    vs.push_back("food");
    cout << vs.size() << " " << vs.capacity() << endl; 

    vs.push_back("wahhhh");
    cout << vs.size() << " " << vs.capacity() << endl; 

    return 0;
}
