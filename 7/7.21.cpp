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
//    Sales_data() = default;
    Sales_data(const std::string &str): bookNo(str) {}
    Sales_data(const std::string &str, const unsigned &us, const double & p) : bookNo(str),units_sold(us),revenue(us*p) {}
    Sales_data(std::istream &in){read(std::cin,*this);}
    Sales_data() :bookNo(""),units_sold(0),revenue(0) {}

    
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
    Sales_data total(std::cin);

    if(std::cin){
        Sales_data trans(std::cin);
        while(std::cin){
            if(trans.isbn() == total.isbn()){
                total.combine(trans);
            }else{
                print(std::cout,total);
                total = trans;
            }
            //read(std::cin,trans);
            trans = Sales_data (std::cin);
        }
        print(std::cout,total);
    }else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
