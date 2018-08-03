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
private:
	string name;

};

class Circle : public Shape{	
public:
	Circle() = default;

private:
	coor center;
	double radius = 0.0;
};
