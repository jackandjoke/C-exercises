#include<iostream>

using std::cout;
using std::endl;




class Foo{
public:
    Foo sorted() && {cout << "Foo sorted() &&\n";};
    Foo sorted() const &{cout << "Foo sorted() const &\n";
        //13.56
        /*
        Foo ret(*this); 
        return ret.sorted();
        */
        //13.57
        return Foo(*this).sorted();
    }

};


int main(){
    Foo f;
    f.sorted();
    


    return 0;
}


