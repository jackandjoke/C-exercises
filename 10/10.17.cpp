#include<iostream>
#include<vector>
#include<string>
#include<algorithm>



struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data(std::string isbn){bookNo = isbn;}
};


int main(){
    std::vector<Sales_data> vecs = {Sales_data("1995-10"),Sales_data("1994-5"),Sales_data("1934"),Sales_data("1920-10-3"),Sales_data("1933-11")};
    std::sort(vecs.begin(),vecs.end(),[](const Sales_data &s1, const Sales_data &s2) {return s1.bookNo.size() < s2.bookNo.size();});
    for(const auto &d : vecs)
        std::cout << d.bookNo << " ";
    std::cout << std::endl;
    return 0;
}
