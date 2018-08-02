#include "15.3.h"

class Bulk_quote2: public Quote{
public:
	Bulk_quote2() = default;
	Bulk_quote2(const string &book, double p, size_t n, double disc) :Quote(book, p), max_qty(n), discount(disc) {}
	double net_price (size_t) const override;

private:
	size_t max_qty;
	double discount;
};

double Bulk_quote2::net_price(size_t n) const{
	double ret;
	ret = price * n;
	if(n <= max_qty)
		ret *= (1 - discount);

	return ret;
}


int main(){
	Bulk_quote2 bq2("second_book", 4.0, 10, 0.3);
	print_total(cout, bq2, 5);
	print_total(cout, bq2, 20);
	return 0;
}
