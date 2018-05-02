#include<iostream>

class Account{

public:
    static double get_rate() {return rate;}
    static double get_today_rate(){return today_rate;}
    double get_saving(){return saving;}
    Account(double c=today_rate):saving(c){}
private:
    static double rate;
    double saving;
    static constexpr double today_rate = 0.23;
};


double Account::rate = 0.1;
constexpr double Account::today_rate;

int main(){
    std::cout << Account::get_rate()<<std::endl;
    Account a;
    std::cout <<a.get_saving()<< std::endl;
}
