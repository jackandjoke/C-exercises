#include<memory>

using std::unique_ptr;


int main(){
    unique_ptr<int> p(new int(1024));
    unique_ptr<int> q = p;
    unique_ptr<int> q2(p);

    return 0;
}
