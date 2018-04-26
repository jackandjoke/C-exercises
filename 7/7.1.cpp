#include<iostream>
#include<string>


//Sales_data defined in chapter 2.6.1
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};



int main(){
    Sales_data total;
    if(std::cin >> total.bookNo >> total.units_sold >> total.revenue){
        Sales_data trans;
        while(std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue){
            if(trans.bookNo == total.bookNo){
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }else{
                std::cout << "Book (ISBN) " << total.bookNo <<": "
                          << "sold " << total.units_sold << ","
                          << "total revenue are " << total.revenue <<std::endl;
                total = trans;
            }
        }
        std::cout << "Book (ISBN) " << total.bookNo <<": "
                  << "sold " << total.units_sold << ","
                  << "total revenue are " << total.revenue <<std::endl;
    }else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
