#include<string>


typedef std::string Type;
Type initVal(){ return Type {};}

class Exercise{
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal(){ return Type {};}
private:
    int val;
};

Exercise::Type Exercise::setVal(Type parm){
    val = parm + initVal();
    return val;
}



int main(){
    Exercise a;
    return 0;

}
