#include<iostream>
#include<string>


//Sales_data defined in chapter 2.6.1
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    
    Sales_data & combine(const Sales_data &rhs);
    std::string isbn() const{ return bookNo;}
};

Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}



int main(){
    Sales_data total;
    double price;
    if(std::cin >> total.bookNo >> total.units_sold >> price){
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while(std::cin >> trans.bookNo >> trans.units_sold >> price){
            trans.revenue = trans.units_sold * price;
            if(trans.isbn() == total.isbn()){
                total.combine(trans);
            }else{
                std::cout << "Book (ISBN) " << total.isbn() <<": "
                          << "sold " << total.units_sold << ","
                          << "total revenue are " << total.revenue <<std::endl;
                total = trans;
            }
        }
        std::cout << "Book (ISBN) " << total.isbn() <<": "
                  << "sold " << total.units_sold << ","
                  << "total revenue are " << total.revenue <<std::endl;
    }else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
