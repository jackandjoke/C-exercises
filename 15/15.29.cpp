#include "15.26.h"
#include<vector>
#include<memory>
using namespace std;

class Bulk_quote: public Quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double sales_price, size_t cnt, double disc): Quote(book,sales_price),min_qty(cnt),discount(disc) {}
	double net_price(size_t) const override;

	Bulk_quote& operator=(Bulk_quote&);
	Bulk_quote(const Bulk_quote&);
	Bulk_quote(Bulk_quote&&);

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

Bulk_quote& Bulk_quote::operator=(Bulk_quote &rhs){
	if(&rhs != this){
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
	}
	return *this;
}

Bulk_quote::Bulk_quote(const Bulk_quote &rhs): Quote(rhs),min_qty(rhs.min_qty),discount(rhs.discount){}
Bulk_quote::Bulk_quote(Bulk_quote &&rhs): Quote(rhs),min_qty(move(rhs.min_qty)),discount(move(rhs.discount)){}


int main(){
	Quote qt("first_book",3);

	Bulk_quote bq("second_book",3,10,0.2);

	vector<shared_ptr<Quote> > vq;
	vq.push_back(make_shared<Quote>(qt));
	vq.push_back(make_shared<Bulk_quote>(bq) );

	print_total(cout, *vq[0], 10);
	print_total(cout, *vq[1], 20);

	return 0;
}
