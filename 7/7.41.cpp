#include<iostream>
#include<string>
#include<istream>
#include<ostream>

struct Sales_data;
std::istream & read(std::istream &in, Sales_data &rhs);


//Sales_data defined in chapter 2.6.1
struct Sales_data{

friend Sales_data add(const Sales_data &,const Sales_data);
friend std::istream & read(std::istream &,Sales_data &);
friend std::ostream & print(std::ostream &,const Sales_data &);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    Sales_data(const std::string &str, const unsigned &us, const double & p) : bookNo(str),units_sold(us),revenue(us*p) { std::cout << "Sales_data (str, us, p)\n"; }
    Sales_data():Sales_data("",0,0.0) { std::cout << "Sales_data()\n";}
    Sales_data(const std::string &str): Sales_data(str,0,0.0) { std::cout << "Sales_data(str)\n";}
    Sales_data(std::istream &in):Sales_data(){read(std::cin,*this);std::cout << "Sales_data(istream)\n";}

    
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
    std::cout << "constructing a\n";
    Sales_data a;
    std::cout << "a constructed\n";

    std::cout << "constructing b\n";
    Sales_data b("bbbbbbb");
    std::cout << "b constructed\n";

    std::cout << "constructing c\n";
    Sales_data c("c",2,5.3);
    std::cout << "c constructed\n";

    std::cout << "constructing d\n";
    Sales_data d(std::cin);
    std::cout << "d constructed\n";
    return 0;
}
