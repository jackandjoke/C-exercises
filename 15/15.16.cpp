#include "15.11.h"

class Disc_quote: public Quote{
public:
	Disc_quote() = default;
	Disc_quote(const string &book, double p, size_t n, double disc):Quote(book,p),quantity(n),discount(disc){}
	virtual double net_price(size_t) const = 0;


protected:
	size_t quantity = 0;
	double discount = 0.0;

};

class Bulk_quote: public Disc_quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double p, size_t n, double disc ):Disc_quote(book,p,n,disc){}
	double net_price(size_t) const override;
};

double Bulk_quote::net_price(size_t n) const {
	double ret = n * price;
	if(n >= quantity)
		ret *= (1-discount); 
	return ret;
}

class Bulk_quote2: public Disc_quote{
public:
	Bulk_quote2() = default;
	Bulk_quote2(const string &book, double p, size_t n, double disc ):Disc_quote(book,p,n,disc){}
	double net_price(size_t) const override;
};
double Bulk_quote2::net_price(size_t n) const{
	double ret = n * price;
	if( n <= quantity)
		ret *= (1-discount);
	return ret;
}


int main(){
	Bulk_quote bq("third_book",5.0,10,0.5);
	print_total(cout, bq, 5);
	print_total(cout, bq, 20);
	Bulk_quote2 bq2("fourth_book",10,20,0.5);
	print_total(cout, bq2, 5);
	print_total(cout, bq2, 25);
	return 0;
}
