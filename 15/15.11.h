#include<iostream>
#include<string>
#include<ostream>

using namespace std;

class Quote{
public:
	Quote() = default;
	Quote(const string &book, double sales_price):
		bookNo(book), price(sales_price){}
	string isbn() const {return bookNo;}
	virtual double net_price(size_t n) const {return n*price;}

	virtual void debug();


	virtual ~Quote() = default;

protected:
	double price = 0.0;

private:
	string bookNo;
};

double print_total(ostream &os, const Quote &item, size_t n){
	double ret = item.net_price(n);
	os  << "ISBN: " << item.isbn()
		<< " # sold " << n << " total due: " << ret << endl;		
	return ret;
}

void Quote::debug(){
	cout << "Class Quote have members:\n" 
		 << "price: " << price << "\n"
		 << "bookNo: " << bookNo << endl;
}
