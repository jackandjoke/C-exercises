#include "15.11.h"

class Bulk_quote: public Quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double sales_price, size_t cnt, double disc): Quote(book,sales_price),min_qty(cnt),discount(disc) {}
	double net_price(size_t) const override;
	void debug() override ;

private:
	size_t min_qty = 0;
	double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const{
	if(cnt >= min_qty)
		return (1-discount)*price*cnt;
	else
		return price * cnt;
}

void Bulk_quote:: debug(){
	cout << "Class Bulk_quote have members: \n"
		 << "min_qty: " << min_qty << endl
		 << "discount: " << discount << endl;
}


int main(){
	Quote qt("first_book",3);
	print_total(cout, qt, 10);

	Bulk_quote bq("first_book",3,10,0.2);
	print_total(cout, bq, 10 );

	qt.debug();
	bq.debug();
	return 0;
}
