#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>

/*
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data(std::string bk):bookNo(bk){}
    Sales_data(std:: istream &in){ in >> bookNo; in >> units_sold; in >> revenue;}
    
    std::string isbn() const{ return bookNo;}
};


int main(){
    std::vector<Sales_data> vsales;
    std::istream_iterator<Sales_data> in_begin(std::cin), in_end;
    if(in_begin != in_end){
        vsales.push_back(*in_begin);
    }else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    std::sort(vsales.begin(),vsales.end(),[](const Sales_data &lhs, const Sales_data &rhs){return lhs.isbn() < rhs.isbn();}); 
    for(auto begin = vsales.begin(), end = begin; begin != vsales.end(); begin = end+1){
        end = std::find_if(begin,vsales.end(),[begin](const Sales_data &rhs){ return rhs.isbn() != (*begin).isbn();});
        auto val = std::accumulate(begin,end,Sales_data((*begin).isbn()),[](const Sales_data &lhs, const Sales_data &rhs){return lhs.units_sold * lhs.revenue + rhs.units_sold*rhs.revenue; });
        std::cout << (*begin).isbn() << " "<< val << std::endl;
    }

    return 0;
}
*/
