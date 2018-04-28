#include<string>
#include<istream>
#include<ostream>
#include<iostream>
struct Person{
friend std::istream &read(std::istream &, Person &);
friend std::ostream &print(std::ostream&, const Person &);
private:
    std::string name;
    std::string address;
public:

    Person() = default;
    Person(const std::string &nm):name(nm) {}
    Person(const std::string &nm, const std::string &ad):name(nm),address(ad) {}
    Person(std::istream &);


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

Person::Person(std::istream &is){
    read(is,*this);
}


int main(){
    Person item1;
    Person item2("jack");
    Person item3("tom","peking");
    Person item4(std::cin);

    print(std::cout,item1);
    std::cout << std::endl;
    print(std::cout,item2);
    std::cout << std::endl;
    print(std::cout,item3);
    std::cout << std::endl;
    print(std::cout,item4);
    std::cout << std::endl;
    return 0;
}
