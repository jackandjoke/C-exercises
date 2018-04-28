#include<string>
#include<istream>
#include<ostream>
struct Person{
    std::string name;
    std::string address;
    std::string get_name() const{ return name;}
    std::string get_address() const{return address;}
};


std::istream & read(std::istream &in, Person &rhs){
    in >> rhs.name >> rhs.address;
    return in;
}

std::ostream & print(std::ostream &os, const Person &rhs){
    os << rhs.name << " "
       << rhs.address;
    return os;
}


int main(){
    return 0;
}
