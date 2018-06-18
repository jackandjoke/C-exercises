#include<iostream>
#include<memory>


using namespace std;


int main(){
    allocator<string> alloc;
    int n =10;
    auto const p = alloc.allocate(n);
    string *q  = p;
    string str;
    while( q != p + n && cin  >> str){
        alloc.construct(q++,str);
    }
    while(p != q){
        cout << *(--q)<< " ";
        alloc.destroy(q);
    }
    alloc.deallocate(p,n);
    cout << endl;


    return 0;
}
