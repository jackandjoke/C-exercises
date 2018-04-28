#include<iostream>
#include<string>
#include<istream>
#include<ostream>

struct Sales_data;
std::istream & read(std::istream &in, Sales_data &rhs);


//Sales_data defined in chapter 2.6.1
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data() = default;
    Sales_data(const std::string &str): bookNo(str) {}
    Sales_data(const std::string &str, const unsigned &us, const double & p) : bookNo(str),units_sold(us),revenue(us*p) {}
    Sales_data(std::istream &in){read(std::cin,*this);}

    
    Sales_data & combine(const Sales_data &rhs);
    std::string isbn() const{ return bookNo;}
};



Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs; 
    sum.combine(rhs);
    return sum;
}

std::istream & read(std::istream &in, Sales_data &rhs){
    double price;
    in >> rhs.bookNo >> rhs.units_sold >>  price;
    rhs.revenue = rhs.units_sold * price;
    return in;
}

std::ostream & print(std::ostream &os, const Sales_data &rhs){
    os << rhs.isbn() << " " << rhs.units_sold << " "
       << rhs.revenue << std::endl;
    return os;
}





int main(){

    Sales_data item0;
    Sales_data item1("abcd");
    Sales_data item2("abcd",10,5);
    Sales_data item3(std::cin);
    std::cout << "item0 is ";
    print(std::cout,item0);
    std::cout << "item1 is ";
    print(std::cout,item1);
    std::cout << "item2 is ";
    print(std::cout,item2);
    std::cout << "item1 combine with item 2 are ";
    print(std::cout,item1.combine(item2));
    std::cout << "item3 is ";
    print(std::cout,item3);

    return 0;
}
