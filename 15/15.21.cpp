#include<iostream>
#include<string>
#include<utility>


using namespace std;


class Shape{
public:
	using coor = pair<double,double>;
	Shape() = default;
	Shape(const string & str):name(str) {}

	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	void print_total() const;
private:
	string name;

};

void Shape::print_total() const{	
	cout << "name: " << name << endl;
	cout << "area: " << area() << endl;
	cout << "perimeter: " << perimeter() << endl;
}

class Circle : public Shape{	
public:
	Circle() = default;
	Circle(const string &name, coor c, double r) : Shape(name),center(c), radius(r) {}

	double area() const override;
	double perimeter()const override;

private:
	coor center;
	double radius = 0.0;
};

double Circle::area()const {
	return 3.14 * radius * radius;
}
double Circle::perimeter()const{
	return 2 * 3.14 * radius;
}

class Square: public Shape{
public:
	Square() = default;
	Square(const string &name, double l, double w): length(l),width(w),Shape(name){}

	double area()const override;
	double perimeter() const override;
private:
	double length = 0.0, width = 0.0;
};

double Square::area()const{
	return length * width;
}
double Square::perimeter() const{
	return 2 * (length + width);
}


int main(){
	Circle c("first circle",make_pair(0.0,0.0),1.0);
	c.print_total();
	Square sq("first square", 2.0,5.0);
	sq.print_total();
	
	return 0;
}
